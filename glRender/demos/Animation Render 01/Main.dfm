object MainForm: TMainForm
  Left = 337
  Top = 79
  Caption = 'svsd_val GLRender Sample 03'
  ClientHeight = 591
  ClientWidth = 615
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
    OnClick = GLRenderClick
    OnMouseMove = GLRenderMouseMove
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = Timer1Timer
    Left = 204
    Top = 4
  end
end
