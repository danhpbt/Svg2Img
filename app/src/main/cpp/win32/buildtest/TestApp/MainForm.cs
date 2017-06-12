using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.Windows.Forms;

using NativeWrapper;

namespace TestApp
{
    public partial class MainForm : Form
    {
        private System.Drawing.Bitmap m_Bitmap;
        private System.Drawing.Bitmap m_Undo;
        private double Zoom = 1.0;

        private Svg2Img m_Svg2Img;

        public MainForm()
        {
            InitializeComponent();
             m_Svg2Img = new Svg2Img(m_Bitmap);
        }

        private void menuMain_Click(object sender, EventArgs e)
        {
            if (sender == menu_File_Open)
            {
                File_Open();
            }
            else if (sender == menu_File_Save)
            {
                File_Save();
            }
            else if (sender == menu_File_Exit)
            {
                File_Exit();
            }
            else if (sender == menu_Edit_Undo)
            {
                Edit_Undo();
            }
            else if (sender == menu_Agg2D_Fill)
            {
                Agg2D_Fill();
            }

        }


        #region MenuItem Event

        private void File_Open()
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            openFileDialog.Title = "Open Image";
            openFileDialog.RestoreDirectory = true;
            openFileDialog.Filter = "Image Files(*.BMP;*.JPG;*.GIF;*.PNG)|*.BMP;*.JPG;*.GIF;*.PNG|Bitmaps (*.bmp)|*.bmp|JPEG images (*.jpg)|*.jpg|PNG images (*.png)|*.png|TIF images(*.tif)|*.tif|GIF images(*.gif)|*.gif";

            if (DialogResult.OK == openFileDialog.ShowDialog())
            {
                m_Bitmap = (Bitmap)Bitmap.FromFile(openFileDialog.FileName, false);
                panelCanvas.Invalidate();
            }
        }

        private void File_Save()
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();

            saveFileDialog.InitialDirectory = "c:\\";
            saveFileDialog.Filter = "PNG files (*.png)|*.png|Bitmap files (*.bmp)|*.bmp|Jpeg files (*.jpg)|*.jpg|All valid files (*.bmp/*.jpg)|*.bmp/*.jpg";
            saveFileDialog.FilterIndex = 1;
            saveFileDialog.RestoreDirectory = true;

            if (DialogResult.OK == saveFileDialog.ShowDialog())
            {
                switch (saveFileDialog.FileName.Substring(saveFileDialog.FileName.Length - 3, 3).ToLower())
                {
                    case "bmp":
                        m_Bitmap.Save(saveFileDialog.FileName, ImageFormat.Bmp);
                        break;
                    case "png":
                        m_Bitmap.Save(saveFileDialog.FileName, ImageFormat.Png);
                        break;
                    case "jpg":
                    case "jpe":
                    case "peg":
                        m_Bitmap.Save(saveFileDialog.FileName, ImageFormat.Jpeg);
                        break;
                    case "tif":
                    case "iff":
                        m_Bitmap.Save(saveFileDialog.FileName, ImageFormat.Tiff);
                        break;
                }
            }
        }

        private void File_Exit()
        {
            this.Close();
        }

        private void Edit_Undo()
        {
            Bitmap temp = (Bitmap)m_Bitmap.Clone();
            m_Bitmap = (Bitmap)m_Undo.Clone();
            m_Undo = (Bitmap)temp.Clone();
            this.panelCanvas.Invalidate();
        }

        private void Agg2D_Fill()
        {
            m_Undo = (Bitmap)m_Bitmap.Clone();

            m_Svg2Img.SetImage(m_Bitmap);
            m_Svg2Img.ApplyAgg2DTest();

            panelCanvas.Invalidate();
        }
        

        #endregion

        private void panelCanvas_Paint(object sender, PaintEventArgs e)
        {
            if (m_Bitmap != null)
            {
                Graphics g = e.Graphics;
                SolidBrush brush = new SolidBrush(Color.White);
                Rectangle rect = new Rectangle(0, 0, (int)(m_Bitmap.Width * Zoom), (int)(m_Bitmap.Height * Zoom));
                g.FillRectangle(brush, rect);
                g.DrawImage(m_Bitmap, rect);
            }  
        }


    }
}
