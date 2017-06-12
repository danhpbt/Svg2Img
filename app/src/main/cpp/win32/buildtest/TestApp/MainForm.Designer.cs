namespace TestApp
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuMain = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_File_Open = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_File_Save = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.menu_File_Exit = new System.Windows.Forms.ToolStripMenuItem();
            this.agg2dToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_Agg2D_Fill = new System.Windows.Forms.ToolStripMenuItem();
            this.panelCanvas = new System.Windows.Forms.Panel();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menu_Edit_Undo = new System.Windows.Forms.ToolStripMenuItem();
            this.menuMain.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuMain
            // 
            this.menuMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.agg2dToolStripMenuItem});
            this.menuMain.Location = new System.Drawing.Point(0, 0);
            this.menuMain.Name = "menuMain";
            this.menuMain.Size = new System.Drawing.Size(684, 24);
            this.menuMain.TabIndex = 0;
            this.menuMain.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menu_File_Open,
            this.menu_File_Save,
            this.toolStripSeparator1,
            this.menu_File_Exit});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // menu_File_Open
            // 
            this.menu_File_Open.Name = "menu_File_Open";
            this.menu_File_Open.Size = new System.Drawing.Size(152, 22);
            this.menu_File_Open.Text = "Open";
            this.menu_File_Open.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // menu_File_Save
            // 
            this.menu_File_Save.Name = "menu_File_Save";
            this.menu_File_Save.Size = new System.Drawing.Size(152, 22);
            this.menu_File_Save.Text = "Save";
            this.menu_File_Save.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(149, 6);
            // 
            // menu_File_Exit
            // 
            this.menu_File_Exit.Name = "menu_File_Exit";
            this.menu_File_Exit.Size = new System.Drawing.Size(152, 22);
            this.menu_File_Exit.Text = "Exit";
            this.menu_File_Exit.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // agg2dToolStripMenuItem
            // 
            this.agg2dToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menu_Agg2D_Fill});
            this.agg2dToolStripMenuItem.Name = "agg2dToolStripMenuItem";
            this.agg2dToolStripMenuItem.Size = new System.Drawing.Size(55, 20);
            this.agg2dToolStripMenuItem.Text = "Agg2D";
            // 
            // menu_Agg2D_Fill
            // 
            this.menu_Agg2D_Fill.Name = "menu_Agg2D_Fill";
            this.menu_Agg2D_Fill.Size = new System.Drawing.Size(152, 22);
            this.menu_Agg2D_Fill.Text = "Fill";
            this.menu_Agg2D_Fill.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // panelCanvas
            // 
            this.panelCanvas.BackColor = System.Drawing.SystemColors.ControlLight;
            this.panelCanvas.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelCanvas.Location = new System.Drawing.Point(0, 24);
            this.panelCanvas.Name = "panelCanvas";
            this.panelCanvas.Size = new System.Drawing.Size(684, 323);
            this.panelCanvas.TabIndex = 1;
            this.panelCanvas.Paint += new System.Windows.Forms.PaintEventHandler(this.panelCanvas_Paint);
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menu_Edit_Undo});
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.Size = new System.Drawing.Size(39, 20);
            this.editToolStripMenuItem.Text = "Edit";
            // 
            // menu_Edit_Undo
            // 
            this.menu_Edit_Undo.Name = "menu_Edit_Undo";
            this.menu_Edit_Undo.Size = new System.Drawing.Size(152, 22);
            this.menu_Edit_Undo.Text = "Undo";
            this.menu_Edit_Undo.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(684, 347);
            this.Controls.Add(this.panelCanvas);
            this.Controls.Add(this.menuMain);
            this.MainMenuStrip = this.menuMain;
            this.Name = "MainForm";
            this.Text = "MainForm";
            this.menuMain.ResumeLayout(false);
            this.menuMain.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuMain;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem menu_File_Open;
        private System.Windows.Forms.ToolStripMenuItem menu_File_Save;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem menu_File_Exit;
        private System.Windows.Forms.ToolStripMenuItem agg2dToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem menu_Agg2D_Fill;
        private System.Windows.Forms.Panel panelCanvas;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem menu_Edit_Undo;
    }
}

