using System;
using System.ComponentModel;
//引用命名空间
using System.IO;
using System.Linq;
using System.Windows.Forms;
using CreateFile;
using DeleteFile;
using ExecuteFile;
using filecopy_cut;
using Shell32;



namespace 资源管理器
{
    public partial class Form1 : Form
    {
        //构造函数
        public Form1()
        {
            InitializeComponent();
            this.toolStripComboBox1.Width = this.toolStrip2.Width - 120;
            this.Text = "小仙女";

        }


        //用来判断是剪切还是复制，choose=1表示复制，choose=2表示剪切
        int choose = 0;


        //用来判断是listview还是treeview的文件或文件夹实现复制粘贴
        //judge=false，代表treeview；judge=true代表listview
        bool judge = true;



        private void Form1_Load(object sender, EventArgs e)
        {
            TreeNode rootnode = this.treeView1.Nodes[0];
            rootnode.Expand();

            
            TreeNode ndmydocument = null;
            TreeNode ndmycomputer = null;
            TreeNode ndtrashbin = null;
            foreach (TreeNode nd in rootnode.Nodes)
            {
                if (nd.Name == "ndmydocument") ndmydocument = nd;
                if (nd.Name == "ndmycomputer") ndmycomputer = nd;
                if (nd.Name == "ndtrashbin") ndtrashbin = nd;
            }



            //向【我的电脑】添加子节点

            /*返回值
            Type: System.IO.DriveInfo[]
            DriveInfo 类型的数组，表示计算机上的逻辑驱动器。*/

            DriveInfo[] drives = DriveInfo.GetDrives();
            //将逻辑驱动器添加进【我的电脑】
            foreach (DriveInfo driver in drives)
            {
                TreeNode node = new TreeNode(driver.Name);
                //添加结点图标
                node.ImageKey = "Imageres.disks.ico";
                node.SelectedImageKey = "Imageres.disks.ico";
                //tag用来保存当前结点路径
                node.Tag = driver.RootDirectory.FullName;
                ndmycomputer.Nodes.Add(node);
            }

            //向【我的文档】添加子节点
            string mydocumentfolderpath = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
            DirectoryInfo mydocumentfolder = new DirectoryInfo(mydocumentfolderpath);
            DirectoryInfo[] folders = mydocumentfolder.GetDirectories();
            foreach (DirectoryInfo folder in folders)
            {
                TreeNode node = new TreeNode(folder.Name);
                node.ImageKey = "Imageres.folder.ico";
                node.SelectedImageKey = "Imageres.folder.ico";
                //tag保存当前结点路径
                node.Tag = folder.FullName;
                ndmydocument.Nodes.Add(node);
            }


            //向【回收站】添加子节点
            Shell shell = new Shell();
            Folder recycleBin = shell.NameSpace(10);
            foreach (FolderItem2 recfile in recycleBin.Items())
            {
                TreeNode node = new TreeNode(recfile.Name);
                node.ImageKey = "imageres.folder.ico";
                node.SelectedImageKey = "imageres.folder.ico";
                node.Tag = null;
                ndtrashbin.Nodes.Add(node);
            }

        }


        //动态调节toolStripComboBox1的大小
        private void Form1_SizeChanged(object sender, EventArgs e)
        {

            this.toolStripComboBox1.Width = this.toolStrip2.Width - 120;
        }


        //显示listview
        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {
            //设置toolStripComboBox1显示内容
            //处理鼠标或者见键盘点击
            if (e.Action == TreeViewAction.ByKeyboard || e.Action == TreeViewAction.ByMouse)
            {
                //如果是我的桌面、我的文档或我的电脑这三个
                if (e.Node.Tag == null)
                {
                    //设置toolStripComboBox1显示内容
                    this.toolStripComboBox1.Text = e.Node.Text;
                }
                //其他层显示路径
                else
                {
                    this.toolStripComboBox1.Text = e.Node.Tag.ToString();
                }

            }//if


            //处理listview显示内容
            //每次显示先清除上次的显示内容
            this.listView1.Items.Clear();

            //显示
            if (e.Node.Tag != null)
            {
                string folderPath = e.Node.Tag.ToString();
                DirectoryInfo folder = new DirectoryInfo(folderPath);

                //填写文件夹
                DirectoryInfo[] subfolders = null;
                try
                {
                    subfolders = folder.GetDirectories();
                }
                catch (UnauthorizedAccessException)
                {

                }

                //说明当前目录下有文件夹
                if (subfolders != null)
                {
                    foreach (DirectoryInfo subfolder in subfolders)
                    {
                        ListViewItem item = new ListViewItem(new string[]{
                            subfolder.Name,
                            "文件夹",
                            "",
                            ""
                        }, "imageres.folder.ico");

                        //item.tag保存文件夹路径
                        item.Tag = subfolder.FullName;
                        item.Name = subfolder.Name;

                        listView1.Items.Add(item);
                    }
                }


                //填写文件
                //file可能存在权限问题
                FileInfo[] files = null;
                try
                {
                    files = folder.GetFiles();
                }
                catch (UnauthorizedAccessException)
                {

                }
                //说明有文件
                if (files != null)
                {
                    foreach (FileInfo file in files)
                    {
                        ListViewItem item = new ListViewItem(new string[]{
                        file.Name,
                        "文件",
                        GetFileSize(file),
                        file.LastWriteTime.ToString()
                        }, "imageres.file.ico");

                        item.Tag = file.FullName;
                        item.Name = file.Name;

                        listView1.Items.Add(item);
                    }
                }
            }//大if
        }



        //设置listview显示格式
        private string GetFileSize(FileInfo file)
        {
            string result = "";
            long fileSize = file.Length;
            //GB
            if (fileSize >= 1024 * 1024 * 1024)
            {
                result = string.Format("{0:########0.00} GB", ((double)fileSize) / (1024 * 1024 * 1024));
            }
            //MB
            else if (fileSize >= 1024 * 1024)
            {
                result = string.Format("{0:####0.00} MB", ((double)fileSize) / (1024 * 1024));
            }
            //KB
            else if (fileSize >= 1024)
            {
                result = string.Format("{0:####0.00} KB", ((double)fileSize) / 1024);
            }
            //B
            else
            {
                result = string.Format("{0} Bytes", fileSize);
            }
            return result;

        }




        //对treeview，每点击一个结点，再展开这个结点
        private void treeView1_AfterExpand(object sender, TreeViewEventArgs e)
        {
            if (e.Node.Parent == null) return;
            //对当前点击结点进行操作
            foreach (TreeNode node in e.Node.Nodes)
            {
                //首先判断点击结点是不是根节点（桌面节点），根节点的tag=null
                if (node.Tag == null) continue;

                node.Nodes.Clear();

                //获取点击结点的标志
                DirectoryInfo folder = new DirectoryInfo(node.Tag.ToString()); ;

                //展开点击结点的下一层结点
                DirectoryInfo[] subfolders = null;
                try
                {
                    subfolders = folder.GetDirectories();
                }
                catch (Exception)
                {
                    //
                }

                if (subfolders != null)
                {
                    foreach (DirectoryInfo subfolder in subfolders)
                    {

                        TreeNode subnode = new TreeNode(subfolder.Name);
                        subnode.ImageKey = "Imageres.folder.ico";
                        subnode.SelectedImageKey = "Imageres.folder.ico";
                        subnode.Tag = subfolder.FullName;
                        node.Nodes.Add(subnode);
                    }
                }

            }

        }



        //treeview右上角x的功能
        private void toolStripButton8_Click(object sender, EventArgs e)
        {
            //点击x隐藏显示目录树
            this.panel1.Hide();
            //设置初始文件按钮状态为关闭
            this.toolStripButton5.Checked = false;
        }


        //文件夹摁扭功能
        private void toolStripButton5_Click(object sender, EventArgs e)
        {
            //文件点一次关闭，点一次打开，初始状态是false
            if (this.toolStripButton5.Checked)
            {
                this.panel1.Show();
            }
            else
            {
                //点击文件显示目录树
                this.panel1.Hide();
            }
        }



        //实现向上按钮功能
        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            TreeNode node = treeView1.SelectedNode;
            TreeNode parentnode = node.Parent;
            if (parentnode != null)
            {
                this.treeView1.SelectedNode = parentnode;
            }
        }



        //实现剪切功能
        private void 剪切ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            choose = 2;

            copyclipboard();

        }



        //实现粘贴功能
        private void 粘贴ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ccfile ccfile=new ccfile();

            //先从剪切板获得源文件路径
            string srcdir = null;
            

            //获取目的路径
            string desdir = null;

            TreeNode node = treeView1.SelectedNode;


            //判断源路径是否为空
            try
            {
                srcdir = Clipboard.GetText();
            }

            catch (ArgumentNullException)
            {
                MessageBox.Show("不可粘贴！");
            }


            //判断目的路径是否为空
            try
            {
                desdir = this.toolStripComboBox1.Text;
            }

            catch (ArgumentNullException)
            {
                MessageBox.Show("不可粘贴!");
            }

             //说明是listview
            if (judge == true) desdir = desdir.Remove(desdir.LastIndexOf("\\"));

            if (srcdir != null && desdir != null)
            {
                if(srcdir.Contains(';'))
                {
                    srcdir = srcdir.Remove(srcdir.LastIndexOf(";"));
                }
                

                //将源文件路径划分开
                string[] str = srcdir.Split(';');

                int i=0;
                while(i<str.Count())
                {
                    ccfile.paste(str[i],desdir,choose);
                    i++;
                }

            }//if


            choose = 0;


            this.treeView1.SelectedNode = node.Parent;

            this.treeView1.SelectedNode = node;

            node.Parent.Collapse();

            node.Parent.Expand();

            node.Expand();

        }




        //实现复制功能
        private void 复制ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            choose = 1;

            copyclipboard();

        }



        //将源文件路径放在剪切板上
        private void copyclipboard()
        {
            Clipboard.Clear();

            TreeNode node = treeView1.SelectedNode;

            if (node.Tag == null)
            {
                MessageBox.Show("该目录不可复制！");
            }
            else
            {
                //说明只有一个文件或者文件夹
                if (listView1.SelectedItems.Count <= 1)
    
                    Clipboard.SetText(this.toolStripComboBox1.Text);

                //多个,只有可能在listview多选
                else
                {
                    string str = null;
                    foreach (ListViewItem item in listView1.SelectedItems)
                    {
                        str += item.Tag.ToString();
                        str += ';';
                    }
                    
                    Clipboard.SetText(str);
                }
            }
           

        }


        private void contextMenuStrip1_Opening(object sender, CancelEventArgs e)
        {
            //加入剪切的控件
            contextMenuStrip1.Items.Add(剪切ToolStripMenuItem);
            //加入复制的控件
            contextMenuStrip1.Items.Add(复制ToolStripMenuItem);
            //加入粘贴的控件
            contextMenuStrip1.Items.Add(粘贴ToolStripMenuItem);
            //加入删除的控件
            contextMenuStrip1.Items.Add(delete);
            //加入重命名的控件
            contextMenuStrip1.Items.Add(rename);
            //加入打开的控件
            contextMenuStrip1.Items.Add(打开NToolStripMenuItem);
        }




        private void listView1_ItemSelectionChanged(object sender, ListViewItemSelectionChangedEventArgs e)
        {
            this.toolStripComboBox1.Text = e.Item.Tag.ToString();
        }


        //处理listview点击事件
        private void listView1_Click(object sender, EventArgs e)
        {
            judge = true;
        }


        //处理treeview点击事件
        private void treeView1_Click(object sender, EventArgs e)
        {
            judge = false;
        }


        //新建文件夹
        private void createFolder_Click(object sender, EventArgs e)
        {
            //获得当前选中的节点
            TreeNode node = treeView1.SelectedNode;

            if (node.Tag != null)
            {
                MyCreate c = new MyCreate();
                string currentPath = node.Tag.ToString();
                c.CreateFolder(currentPath);

                //显示新建的文件夹
                if (node != null)
                {
                    //TreeView.SelectedNode 获取或设置TreeView中选定的树节点
                    TreeNode i = treeView1.SelectedNode;
                    this.treeView1.SelectedNode.Parent.Collapse();
                    this.treeView1.SelectedNode.Parent.Expand();
                    this.treeView1.SelectedNode = i;
                    i.Expand();
                }
            }
        }


        //新建文本文档
        private void createText_Click(object sender, EventArgs e)
        {
            //获得当前选中的节点
            TreeNode node = treeView1.SelectedNode;

            if (node.Tag != null)
            {
                MyCreate c = new MyCreate();
                string currentPath = node.Tag.ToString();
                c.CreateText(currentPath);

                //显示新建的文件
                if (node != null)
                {
                    //TreeView.SelectedNode 获取或设置TreeView中选定的树节点
                    this.treeView1.SelectedNode = node.Parent;
                    this.treeView1.SelectedNode = node;
                }

            }
        }



        //重命名
        private void rename_Click(object sender, EventArgs e)
        {
            //重命名树节点
            if (listView1.SelectedItems.Count == 0)
            {
                treeView1.SelectedNode.BeginEdit();
            }
            //重命名ListView结点
            else
            {
                listView1.FocusedItem.BeginEdit();
            }
        }



        //编辑ListView结点，开始编辑之后触发的事件
        private void listView1_AfterLabelEdit(object sender, LabelEditEventArgs e)
        {
            //获得当前选中的节点
            TreeNode node = treeView1.SelectedNode;
            //原文件的路径(FocusedItem是ListViewItem 类
            string path = listView1.FocusedItem.Tag.ToString();
            if (e.Label != null)
            {
                //重命名之后的文件的路径
                string newpath = Path.Combine(node.Tag.ToString(), e.Label);

                //重命名文件
                if (File.Exists(path))
                {
                    FileInfo file = new FileInfo(path);
                    try
                    {
                        //将指定文件移到新位置并提供指定新文件名的选项
                        file.MoveTo(newpath);
                    }
                    catch (IOException)
                    {
                        MessageBox.Show("存在同名文件，操作失败");
                        listView1.FocusedItem.Text = listView1.FocusedItem.Name;
                    }
                    //e.Label是编辑之后的值
                    listView1.FocusedItem.Name = e.Label;
                    //新的文件名(包含路径)放在Tag中
                    listView1.FocusedItem.Tag = newpath;
                }
                //重命名文件夹
                else
                {
                    DirectoryInfo folder = new DirectoryInfo(path);
                    try
                    {
                        folder.MoveTo(newpath);
                    }
                    catch (IOException)
                    {
                        MessageBox.Show("存在同名文件，操作失败");
                        listView1.FocusedItem.Text = listView1.FocusedItem.Name;
                    }
                    //e.Label是编辑之后的值
                    listView1.FocusedItem.Name = e.Label;
                    //新的文件名(包含路径)放在Tag中
                    listView1.FocusedItem.Tag = newpath;
                }

            }
        }



        //编辑树节点，开始编辑之后触发的事件
        private void treeView1_AfterLabelEdit(object sender, NodeLabelEditEventArgs e)
        {
            //获得当前选中的节点
            TreeNode node = treeView1.SelectedNode;
            // 原文件的路径
            string path = node.Tag.ToString();
            if (e.Label != null)
            {
                //重命名之后的文件的路径
                string newpath = Path.Combine(node.Parent.Tag.ToString(), e.Label);
                //Console.WriteLine(newpath);
                DirectoryInfo folder = new DirectoryInfo(path);
                try
                {
                    folder.MoveTo(newpath);
                }
                catch (IOException)
                {
                    MessageBox.Show("存在同名文件，操作失败");
                    treeView1.SelectedNode.Text = treeView1.SelectedNode.Name;
                }
                //e.Label是编辑之后的值
                treeView1.SelectedNode.Name = e.Label;
                //新的文件名(包含路径)放在Tag中
                treeView1.SelectedNode.Tag = newpath;
            }
        }



        //删除文件/文件夹
        private void delete_Click(object sender, EventArgs e)
        {
            //SelectedItems.Count代表listView中选中的数目
            //删除treeView中的文件
            MyDelete d = new MyDelete();
            if (listView1.SelectedItems.Count == 0)
            {
                string treeViewSeletedFolderPath = treeView1.SelectedNode.Tag.ToString();
                if (treeViewSeletedFolderPath != null)
                {
                    if (d.DeleteFolder(treeViewSeletedFolderPath))
                    {
                        MessageBox.Show("删除成功！");
                    }
                    else MessageBox.Show("删除失败！");
                }
            }

            //删除listView中的文件
            else
            {
                int deleteFiles = 0;
                int deleteFolders = 0;
                bool tag = true;

                ListView.SelectedIndexCollection indexs = listView1.SelectedIndices;
                DirectoryInfo currentFolder = new DirectoryInfo(treeView1.SelectedNode.Tag.ToString());
                //获取本文件夹下的所有子文件夹
                DirectoryInfo[] subFolders = currentFolder.GetDirectories();
                int folderNum = subFolders.Length;
                //Console.WriteLine("folderNum:"+folderNum);
                //获取本文件夹下的所有文件
                FileInfo[] files = currentFolder.GetFiles();

                foreach (int index in indexs)
                {
                    //remove时文件夹中的文件减少i个，剩余文件的index也需要减少i
                    listView1.Items.RemoveAt(index - deleteFiles - deleteFolders);
                    //Console.WriteLine(index);

                    //删除文件
                    if (index >= folderNum)
                    {
                        //文件的路径
                        string filePath = treeView1.SelectedNode.Tag.ToString() + "/"
                            + files[index - folderNum].Name;
                        //若存在文件夹删除失败，则break
                        if (!d.DeleteFile(filePath))
                        {
                            tag = false;
                            break;
                        }
                        deleteFiles++;
                    }

                    //删除文件夹
                    else
                    {
                        //文件夹的路径
                        string folderPath = treeView1.SelectedNode.Tag.ToString() + "/"
                            + subFolders[index].Name;
                        //若存在文件夹删除失败，则break
                        if (!d.DeleteFolder(folderPath))
                        {
                            tag = false;
                            break;
                        }
                        deleteFolders++;
                    }
                }//end foreach
                if (tag) MessageBox.Show("删除成功！");
                else MessageBox.Show("删除失败！");
            }

            TreeNode i = treeView1.SelectedNode;
            treeView1.SelectedNode.Parent.Collapse();
            treeView1.SelectedNode.Expand();
            treeView1.SelectedNode = i;
            i.Expand();
        }



        //执行文件
        private void 打开NToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MyExe ex = new MyExe();
            ex.exeFile(listView1.FocusedItem.Tag.ToString());
        }



        //双击执行文件
        private void listView1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            MyExe ex = new MyExe(); 
            ex.exeFile(listView1.FocusedItem.Tag.ToString());
        }

    }
}
