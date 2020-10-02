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
        public static extern int lex(string name);
        [DllImport("F:\\code\\c#\\mycompiler\\Debug\\lexdll.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int senmatic(string name);
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
            if (openFileDialog1.ShowDialog() == System.Windows.Forms.DialogResult.OK)
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
            richTextBox3.Clear();
      
        
            //txtflag checkflag[3]=new txtflag[3];
            int flag_lex = 0;
            int flag_sematic = 0;
            int sum = 0;
            int count = 0;
            
            flag_lex = lex(filename);
            filename = "F:\\shuchu.txt";
            flag_sematic = senmatic(filename);
            if(flag_lex == 1)
            {
                sum += 1;
            }
            else
            {
                count += 1;
               
            }
            if (flag_sematic == 1)
            {
                sum += 1;
            }
            else
            {
                count += 1;
                
            }
            if (flag_sematic == 0 && flag_lex == 0)
                sum = 0;
            if(count==2)
            {
                count += 1;
            }
            if (sum==0)
            {
                richTextBox3.Text = "------编译成功------  \n" +
                                    "------生成文件:" + count + "------\n";
            }
            else if(flag_lex==1)
            {
                
                richTextBox3.LoadFile("F:\\error.txt", RichTextBoxStreamType.PlainText);
            }
            else if(flag_sematic==1)
            {
                richTextBox3.LoadFile("F:\\grammarerror.txt", RichTextBoxStreamType.PlainText);
            }
        }

        private void 词法分析ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox2.LoadFile("F:\\shuchu.txt", RichTextBoxStreamType.PlainText);
            richTextBox2.SelectAll();
            Font font = new Font(FontFamily.GenericMonospace, 12, FontStyle.Regular);
            this.richTextBox2.SelectionFont = font;

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

        private void 语法分析ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox2.Clear();
        }

        private void 目标代码生成ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox2.Clear();
            richTextBox2.LoadFile("F:\\create.txt", RichTextBoxStreamType.PlainText);
        }

        private void 语义分析ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox2.Clear();
            richTextBox2.LoadFile("F:\\fourout.txt", RichTextBoxStreamType.PlainText);
            richTextBox2.SelectAll();
            Font font = new Font(FontFamily.GenericMonospace, 12, FontStyle.Regular);
            this.richTextBox2.SelectionFont = font;

        }
    }
}
