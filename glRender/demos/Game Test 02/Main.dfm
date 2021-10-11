object Form1: TForm1
  Left = 337
  Top = 79
  Caption = 'svsd_val GLRender Sample 03'
  ClientHeight = 480
  ClientWidth = 640
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
  object GLRender: TGLRender
    Left = 8
    Top = 8
    Width = 297
    Height = 249
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
  object Frust: TFrustum
    Left = 312
    Top = 72
  end
end
