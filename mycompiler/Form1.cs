using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
namespace mycompiler
{
    public partial class mycompiler : Form
    {
        [DllImport("F:\\code\\c#\\mycompiler\\Debug\\lexdll.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int lex();
        string filename = "";
        public mycompiler()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
       


        private void 新建ToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            filename = "";
            this.Text = "无标题-未保存";
        }

        private void 打开ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            openFileDialog1.Filter = "文本文件 |*.txt";
            openFileDialog1.FilterIndex = 1;
            openFileDialog1.InitialDirectory = "F:\\";
            if(openFileDialog1.ShowDialog()==System.Windows.Forms.DialogResult.OK)
            {
                filename = openFileDialog1.FileName;
                richTextBox1.LoadFile(filename, RichTextBoxStreamType.PlainText);
                this.Text = filename + "--mycompiler";
            }
        }

        private void 另存为ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveFileDialog1.Filter = "文本文件 |*.txt";
            saveFileDialog1.FilterIndex = 1;
            saveFileDialog1.InitialDirectory = "F:\\";
            if(saveFileDialog1.ShowDialog()==System.Windows.Forms.DialogResult.OK)
            {
                filename = saveFileDialog1.FileName;
                richTextBox1.SaveFile(filename, RichTextBoxStreamType.PlainText);
                int index = filename.LastIndexOf('\\');
                string text_2 = filename.Substring(index + 1);
                this.Text = text_2 + "--mycompiler";
            }
        }

        private void 保存ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (filename.Length > 0)
            {
                richTextBox1.SaveFile(filename, RichTextBoxStreamType.PlainText);
            }
            else
            {
                另存为ToolStripMenuItem_Click(sender, e);
            }
        }

        private void 编译ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int flag = 0;
            int sum = 0;
            flag=lex();
            sum += flag;
            if (sum!=0)
            {
                richTextBox3.Text = "------编译成功------  \n" +
                                    "------生成文件:" + sum + "------\n";
            }
            else
            {
                richTextBox3.Text = "------编译失败------  \n" +
                                    "------生成文件：1------\n";
            }
        }

        private void 词法分析ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox2.LoadFile("F:\\lexout.txt", RichTextBoxStreamType.PlainText);
        }

        private void richTextBox3_TextChanged(object sender, EventArgs e)
        {
           
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }
    }
}
