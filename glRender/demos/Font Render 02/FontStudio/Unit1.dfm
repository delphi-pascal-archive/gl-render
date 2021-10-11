object Form1: TForm1
  Left = 113
  Top = 114
  AutoScroll = False
  Caption = 'Font Studio 2'
  ClientHeight = 327
  ClientWidth = 548
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 286
    Top = 2
    Width = 267
    Height = 311
    BevelOuter = bvNone
    TabOrder = 2
    object Label2: TLabel
      Left = 10
      Top = 41
      Width = 95
      Height = 13
      Caption = 'Number of Columns:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 8
      Top = 169
      Width = 106
      Height = 13
      Caption = 'Texture Size: 256x256'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 80
      Top = 279
      Width = 105
      Height = 14
      AutoSize = False
      Caption = 'Status: Idle'
      WordWrap = True
    end
    object Button1: TButton
      Left = 14
      Top = 9
      Width = 87
      Height = 25
      Caption = ' Generate Font'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = Button1Click
    end
    object Edit1: TEdit
      Left = 110
      Top = 40
      Width = 26
      Height = 22
      Hint = 'Number of Columns'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      Text = '10'
      OnChange = Edit1Change
    end
    object Button2: TButton
      Left = 9
      Top = 274
      Width = 64
      Height = 25
      Caption = 'Save As...'
      TabOrder = 2
      OnClick = Button2Click
    end
    object GroupBox1: TGroupBox
      Left = 8
      Top = 206
      Width = 249
      Height = 65
      Caption = 'Characters'
      TabOrder = 3
      object Label1: TLabel
        Left = 8
        Top = 16
        Width = 233
        Height = 13
        Caption = 'X-Offset:   Width       Height         Start/End Chars'
      end
      object Edit4: TEdit
        Left = 8
        Top = 32
        Width = 41
        Height = 22
        Hint = 'X Offset'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        Text = '2'
        OnChange = Edit4Change
      end
      object Edit7: TEdit
        Left = 56
        Top = 32
        Width = 41
        Height = 22
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        Text = '20'
        OnChange = Edit7Change
      end
      object Edit8: TEdit
        Left = 104
        Top = 32
        Width = 41
        Height = 22
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        Text = '20'
        OnChange = Edit8Change
      end
      object Edit6: TEdit
        Left = 208
        Top = 32
        Width = 25
        Height = 22
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        Text = '150'
        OnChange = Edit6Change
      end
      object Edit9: TEdit
        Left = 168
        Top = 32
        Width = 25
        Height = 22
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        Text = '33'
        OnChange = Edit9Change
      end
    end
    object Button3: TButton
      Left = 104
      Top = 9
      Width = 89
      Height = 25
      Caption = ' Generate Mask'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnClick = Button3Click
    end
    object TrackBar1: TTrackBar
      Left = 2
      Top = 183
      Width = 159
      Height = 23
      Max = 3
      ParentShowHint = False
      ShowHint = True
      TabOrder = 5
      ThumbLength = 14
      OnChange = TrackBar1Change
    end
    object GroupBox2: TGroupBox
      Left = 160
      Top = 59
      Width = 97
      Height = 150
      Caption = '     Smoothing'
      TabOrder = 6
      object Label5: TLabel
        Left = 5
        Top = 21
        Width = 39
        Height = 13
        Caption = 'Smooth:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Microsoft Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label6: TLabel
        Left = 14
        Top = 44
        Width = 31
        Height = 13
        Caption = 'Offset:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Microsoft Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label8: TLabel
        Left = 6
        Top = 67
        Width = 39
        Height = 13
        Caption = 'Opacity:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Microsoft Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Edit2: TEdit
        Left = 47
        Top = 19
        Width = 34
        Height = 22
        Hint = 'Font Size'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        Text = '1'
      end
      object CheckBox3: TCheckBox
        Left = 5
        Top = 88
        Width = 88
        Height = 15
        Caption = 'Extra-Smooth'
        Checked = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        State = cbChecked
        TabOrder = 1
      end
      object Edit5: TEdit
        Left = 47
        Top = 42
        Width = 34
        Height = 22
        Hint = 'Font Size'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        Text = '1'
      end
      object CheckBox4: TCheckBox
        Left = 5
        Top = 107
        Width = 88
        Height = 15
        Caption = 'Draft'
        Checked = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        State = cbChecked
        TabOrder = 3
      end
      object Button5: TButton
        Left = 16
        Top = 128
        Width = 73
        Height = 17
        Caption = 'Cancel'
        Enabled = False
        TabOrder = 4
        OnClick = Button5Click
      end
      object Edit10: TEdit
        Left = 47
        Top = 65
        Width = 34
        Height = 22
        Hint = 'Font Size'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 5
        Text = '100'
      end
    end
    object GroupBox3: TGroupBox
      Left = 8
      Top = 59
      Width = 150
      Height = 105
      Caption = 'Font'
      TabOrder = 7
      object Label3: TLabel
        Left = 4
        Top = 43
        Width = 23
        Height = 13
        Caption = 'Size:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Microsoft Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Shape1: TShape
        Left = 110
        Top = 66
        Width = 32
        Height = 31
        Pen.Color = clGray
        Pen.Style = psInsideFrame
        OnMouseUp = Shape1MouseUp
      end
      object Label9: TLabel
        Left = 75
        Top = 80
        Width = 33
        Height = 13
        Caption = 'Colour:'
      end
      object Label10: TLabel
        Left = 74
        Top = 44
        Width = 39
        Height = 13
        Caption = 'Squash:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Microsoft Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object ComboBox1: TComboBox
        Left = 4
        Top = 15
        Width = 140
        Height = 21
        ItemHeight = 13
        TabOrder = 0
        Text = 'Choose Font'
        OnChange = ComboBox1Change
      end
      object Edit3: TEdit
        Left = 30
        Top = 41
        Width = 27
        Height = 22
        Hint = 'Font Size'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        Text = '10'
        OnChange = Edit3Change
      end
      object CheckBox1: TCheckBox
        Left = 5
        Top = 65
        Width = 48
        Height = 15
        Caption = 'Bold'
        Checked = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        State = cbChecked
        TabOrder = 2
        OnClick = CheckBox1Click
      end
      object CheckBox2: TCheckBox
        Left = 5
        Top = 81
        Width = 48
        Height = 15
        Caption = 'Italic'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = CheckBox2Click
      end
      object UpDown1: TUpDown
        Left = 57
        Top = 41
        Width = 16
        Height = 22
        Associate = Edit3
        Max = 120
        Position = 10
        TabOrder = 4
      end
      object Edit11: TEdit
        Left = 113
        Top = 41
        Width = 16
        Height = 22
        Hint = 'Font Size'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 5
        Text = '0'
        OnChange = Edit11Change
      end
      object UpDown3: TUpDown
        Left = 129
        Top = 41
        Width = 16
        Height = 22
        Associate = Edit11
        Min = -5
        Max = 5
        TabOrder = 6
      end
    end
    object Button4: TButton
      Left = 196
      Top = 9
      Width = 60
      Height = 25
      Caption = 'Test'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      OnClick = Button4Click
    end
    object CheckBox5: TCheckBox
      Left = 168
      Top = 59
      Width = 14
      Height = 15
      Caption = 'Enable'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 9
      OnClick = CheckBox5Click
    end
    object UpDown2: TUpDown
      Left = 136
      Top = 40
      Width = 16
      Height = 22
      Associate = Edit1
      Position = 10
      TabOrder = 10
    end
    object Button6: TButton
      Left = 192
      Top = 274
      Width = 65
      Height = 25
      Caption = 'About'
      TabOrder = 11
      OnClick = Button6Click
    end
  end
  object Tab: TTabControl
    Left = 8
    Top = 8
    Width = 276
    Height = 290
    TabOrder = 0
    Tabs.Strings = (
      'Main'
      'Mask'
      'Test Area')
    TabIndex = 0
    OnChange = TabChange
    object Image1: TImage
      Left = 11
      Top = 27
      Width = 257
      Height = 257
      Stretch = True
    end
    object Image2: TImage
      Left = 11
      Top = 27
      Width = 257
      Height = 257
      Stretch = True
      Visible = False
    end
    object Image3: TImage
      Left = 11
      Top = 27
      Width = 257
      Height = 257
      Stretch = True
      Visible = False
    end
  end
  object Bar: TProgressBar
    Left = 8
    Top = 304
    Width = 273
    Height = 17
    Smooth = True
    TabOrder = 1
  end
  object Edit12: TEdit
    Left = 8
    Top = 300
    Width = 277
    Height = 21
    TabOrder = 3
    Text = 'Test Sentance'
    Visible = False
  end
  object SaveDialog1: TSaveDialog
    Filter = 'Font Files|*.fnt'
    Title = 'Save Font File'
    Left = 440
    Top = 272
  end
  object ColorDialog1: TColorDialog
    Left = 208
    Top = 4
  end
end
