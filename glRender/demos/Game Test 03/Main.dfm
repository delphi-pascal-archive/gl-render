object Form1: TForm1
  Left = 241
  Top = 128
  Width = 816
  Height = 619
  Caption = 'svsd_val GLRender Sample 03'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object GLRender: TGLRender
    Left = 10
    Top = 10
    Width = 365
    Height = 306
    BPP = 32
    DPP = 24
    SPP = 24
    Fov = 45.000000000000000000
    Z_Min = 1.000000000000000000
    Z_Max = 100.000000000000000000
    FullScreen = False
    Background = clBlack
    VSync = False
    OnMouseMove = GLRenderMouseMove
  end
  object GLTimer1: TGLTimer
    ActiveOnly = True
    Enabled = True
    Interval = 1
    OnTimer = GLTimer1Timer
    Left = 312
    Top = 8
  end
  object XMMusic1: TXMMusic
    Left = 312
    Top = 40
  end
  object GLSound1: TGLSound
    Left = 312
    Top = 72
  end
end
