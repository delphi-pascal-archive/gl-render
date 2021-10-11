unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ExtCtrls, ComCtrls, JPeg;

type
  TForm1 = class(TForm)
    Tab: TTabControl;
    Image1: TImage;
    Image2: TImage;
    Bar: TProgressBar;
    Panel1: TPanel;
    SaveDialog1: TSaveDialog;
    Label2: TLabel;
    Button1: TButton;
    Edit1: TEdit;
    Button2: TButton;
    GroupBox1: TGroupBox;
    Label1: TLabel;
    Edit4: TEdit;
    Edit7: TEdit;
    Edit8: TEdit;
    Button3: TButton;
    TrackBar1: TTrackBar;
    Label4: TLabel;
    GroupBox2: TGroupBox;
    Label5: TLabel;
    Edit2: TEdit;
    CheckBox3: TCheckBox;
    Label6: TLabel;
    Edit5: TEdit;
    GroupBox3: TGroupBox;
    ComboBox1: TComboBox;
    Label3: TLabel;
    Edit3: TEdit;
    CheckBox1: TCheckBox;
    CheckBox2: TCheckBox;
    Image3: TImage;
    Button4: TButton;
    CheckBox4: TCheckBox;
    CheckBox5: TCheckBox;
    Button5: TButton;
    UpDown1: TUpDown;
    UpDown2: TUpDown;
    Edit6: TEdit;
    Edit9: TEdit;
    Label7: TLabel;
    Button6: TButton;
    Label8: TLabel;
    Edit10: TEdit;
    Shape1: TShape;
    Label9: TLabel;
    ColorDialog1: TColorDialog;
    Label10: TLabel;
    Edit11: TEdit;
    UpDown3: TUpDown;
    Edit12: TEdit;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure ComboBox1Change(Sender: TObject);
    procedure Edit1Change(Sender: TObject);
    procedure Edit3Change(Sender: TObject);
    procedure CheckBox1Click(Sender: TObject);
    procedure CheckBox2Click(Sender: TObject);
    procedure Edit4Change(Sender: TObject);
    procedure Edit7Change(Sender: TObject);
    procedure Edit8Change(Sender: TObject);
    procedure DrawFont(Col: integer);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure TabChange(Sender: TObject);
    procedure TrackBar1Change(Sender: TObject);
    procedure CheckBox5Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Edit9Change(Sender: TObject);
    procedure Edit6Change(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Shape1MouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure Edit11Change(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

  FontRec = Record
            T1,U1,T2,U2, W, H: single;
            end;

var
  Form1: TForm1;
  Var F: array of FontRec;
  I: integer;
  CurSize, CharS, CharE: integer;

implementation

{$R *.DFM}
{$R winxp.res}

Procedure ScanFonts;
Var I: integer;
begin

 For I := 0 to Screen.fonts.Count -1 do
  Form1.ComboBox1.Items.Add(screen.Fonts.Strings[I]);

 CharS := 33;
 CharE := 255;
end;

Procedure ChangeTab(Num: integer);
begin
 Form1.Tab.TabIndex := Num;
 form1.Edit12.Visible := false;
 Case Form1.Tab.TabIndex of
 0: begin
      Form1.Image1.Visible := True;
      Form1.Image2.Visible := False;
      Form1.Image3.Visible := False;
    end;
 1: begin
      Form1.Image1.Visible := False;
      Form1.Image2.Visible := True;
      Form1.Image3.Visible := False;
    end;
 2: begin
      Form1.Image1.Visible := False;
      Form1.Image2.Visible := False;
      Form1.Image3.Visible := True;

      form1.Edit12.Visible := true;
    end;
 end;
 Application.ProcessMessages;


end;

procedure TForm1.Button1Click(Sender: TObject);
begin
  DrawFont(Shape1.Brush.Color);
end;

procedure TForm1.DrawFont(Col: integer);
Var X, Y, W, H: integer;

    C: integer;
begin
 W := Image1.Picture.Width-1;
 H := Image1.Picture.Height-1;
 if Form1.Tab.TabIndex < 2 then ChangeTab(0);


 if CharE < CharS then CharE := CharS + 1;
 if CharE > 255 then CharE := 255;
 if CharS > CharE then CharS := CharE - 1;
 if CharS < 0 then CharS := 0;
 Edit9.text := inttostr(CharS);
 Edit6.text := inttostr(CharE);


 SetLength(F, (CharE-CharS)+1);

 patblt(Image1.Picture.Bitmap.Canvas.Handle, 0, 0, W+3, H+3, BLACKNESS);
 With Image1.Picture.Bitmap.canvas do
 begin
  Pen.Color := 0;
  Font.Color := Col;
  Font.Name := Combobox1.Text;
  Font.Size := strtoint(edit3.text);
  Font.Style := [];
  if checkbox1.checked then font.Style := [fsBold];
  if checkbox2.checked then font.Style := font.style + [fsItalic];
  Brush.Color := 0;
 end;
 For C := CharS to charE do
 begin
 X := (C-CharS) mod strtoint(edit1.text) * strtoint(Edit7.text)+strtoint(Edit4.text);
 Y := (C-CharS) div strtoint(edit1.text) * strtoint(Edit8.text);
 F[C-CharS].T1 := X/W;
 F[C-CharS].U1 := Y/H;
 F[C-CharS].W := round(Image1.Picture.Bitmap.Canvas.TextWidth(char(C))+Updown3.Position*0.5)+strtoint(edit5.text)+strtoint(edit2.text);
 F[C-CharS].H := round(Image1.Picture.Bitmap.Canvas.TextHeight(char(C))+updown3.Position*0.5)+strtoint(edit5.text)+strtoint(edit2.text);

 F[C-CharS].T2 := (X+F[C-CharS].W)/W;
 F[C-CharS].U2 := (Y+F[C-CharS].H)/H;

 Image1.Picture.Bitmap.Canvas.TextOut(X,Y, char(C));
 end;
end;

Procedure SaveTGA(filename: string);
{Const
  TGAheader : array [0..11] of byte = (0,0,2,0,0,0,0,0,0,0,0,0);// Uncompressed TGA Header

Var
  tgaFile: integer;
  header : array [0..5] of byte;									// First 6 Useful Bytes From The Header
  imageData: PChar;
  Bit, Bit2: PBytearray;
  Wid, Hgt, X, Y, Add: integer;
}
var
  JPG: TJPEGimage;
  Other: string;


begin
  form1.label7.caption := 'Status: Generating Font';
  form1.Button1.Click;
  form1.checkbox4.checked := False;
  form1.label7.caption := 'Status: Generating Hi-Quality Mask';
  form1.Button3.click;
  application.ProcessMessages;

  jpg := TJpegimage.Create;
  Jpg.CompressionQuality := 100;
  With Jpg do
  begin
    Jpg.Grayscale := false;
    Assign(form1.Image1.picture.bitmap);
    SaveToFile(Filename);

    application.ProcessMessages;

    Jpg.Grayscale := true;
    Other := copy(Filename, 1, length(filename)-3) + 'jpg';
    Assign(Form1.image2.Picture.Bitmap);
    SavetoFile(Other);
  end;

  Jpg.Free;

  (*
  form1.label7.caption := 'Status: Writing File Header';
  TgaFile := FileCreate(filename);
  FileWrite(tgafile, TGAHeader, sizeof(TGAHeader));

  wid :=  form1.image1.picture.Bitmap.Width;
  Hgt :=  form1.image1.picture.Bitmap.Height;

  header[0] := lobyte(Wid);
  header[1] := hibyte(Wid);
  header[2] := lobyte(Hgt);
  header[3] := hibyte(Hgt);
  Header[4] := 32;

  FileWrite(tgaFile, header, sizeof(header));

  form1.Bar.position := 3;
  application.ProcessMessages;


  form1.label7.caption := 'Status: Allocating Data Space';
  GetMem(imageData, Wid*Hgt*4);		// Reserve Memory To Hold The TGA Data

  form1.label7.caption := 'Status: Compiling Data';
  application.ProcessMessages;

  For Y := 0 to hgt-1 do
  begin
    Bit := Form1.Image1.Picture.Bitmap.ScanLine[Y];
    Bit2 := Form1.Image2.Picture.Bitmap.ScanLine[Y];
  For X := 0 to wid-1 do
  begin
     Add := (((hgt-1)-Y)*(Wid)+X)*4;
     ImageData[Add] := char(Bit[X*3+2]);
     ImageData[Add+1] := char(Bit[X*3+1]);
     ImageData[Add+2] := char(Bit[X*3]);
     ImageData[Add+3] := char(Bit2[X*3]);
  end;
  {if X mod 50 = 0 then
  begin
   form1.Bar.position := round((X/(Wid-1))*100);
   form1.label7.caption := 'Status: Compiling Data ' + inttostr(form1.bar.position)+'%';
   application.ProcessMessages;
  end;}
  end;
  fileWrite(tgafile, imageData^, wid*Hgt*4);
  Form1.bar.position := 90;
  application.processmessages;
  freemem(imagedata, wid*hgt*4);
  Form1.bar.position := 100;
  *)
  form1.Bar.Position := 0;
end;

procedure TForm1.Button2Click(Sender: TObject);
Var Fi, F2: TFileStream;
    I, Data: integer;
    Filename, Other: string;
    EndPos, CutPos: longint;
begin
 SaveDialog1.FilterIndex := 1;
 SaveDialog1.Title := 'Save Font File';
 if SaveDialog1.Execute then
 begin
  Filename := Savedialog1.filename;
  if pos('.', Savedialog1.filename) > 0 then
  begin
    I := pos('.', Savedialog1.filename);
    if uppercase(Copy(Savedialog1.filename, I+1, 3)) <> 'FNT' then
    filename := copy(filename, 1, I) + 'fnt';
  end
  else
  begin
    filename := savedialog1.filename + '.fnt';
  end;

    SaveTGA(FileName);
    Other := Copy(filename, 1, length(Filename)-3)+'jpg';
  F2 := TFileStream.Create(Other, fmOpenRead);

  Fi := TFileStream.Create(filename, fmOpenWrite);
   CutPos := Fi.Seek(0, soFromEnd);
   Fi.CopyFrom(F2, 0);
   F2.free;

   EndPos := Fi.Seek(0, soFromEnd);


  label7.caption := 'Status: Saving Font File';
  Data := High(F);
  Fi.Write(Data, sizeof(integer));
  Data := strtoint(edit9.Text); //Start Character
  Fi.Write(Data, sizeof(integer));

  Data := strtoint(edit5.Text)+StrtoInt(edit2.text); //Smooth Stuff
  Fi.Write(Data, sizeof(integer));

   For I := 0 to high(F) do
   begin
     Fi.Write(F[I], sizeof(FontRec));
   end;
   Fi.Write(CutPos, sizeof(longint));
   Fi.Write(EndPos, sizeof(longint));

   Fi.Free;
   DeleteFile(Other);
  end;

  label7.caption := 'Status: Done!';

end;

procedure TForm1.FormCreate(Sender: TObject);
Var X,Y: integer;
begin
  ScanFonts;
      CurSize := 0;
      X:=256;Y:=X;
      Image1.Picture.Bitmap.Width := X;
      Image1.Picture.Bitmap.Height := y;
      Image2.Picture.Bitmap.Width := X;
      Image2.Picture.Bitmap.Height := y;
      Image3.Picture.Bitmap.Width := X;
      Image3.Picture.Bitmap.Height := y;
      patblt(Image1.Picture.Bitmap.Canvas.Handle, 0, 0, X, Y, BLACKNESS);
      patblt(Image2.Picture.Bitmap.Canvas.Handle, 0, 0, X, Y, BLACKNESS);
      Image3.Picture.Bitmap.Canvas.Brush.Color := clBtnFace;
      Image3.Picture.Bitmap.Canvas.Rectangle(0,0,X,Y);

      changeTab(0);
      Button1.Click;


end;

procedure TForm1.ComboBox1Change(Sender: TObject);
begin
 Button1.Click;
end;

procedure TForm1.Edit1Change(Sender: TObject);
begin
 if (Edit1.text = '') or (Edit1.text = '0') then
 begin
  Edit1.selstart := Length(Edit1.text);
  Edit1.text := '1';
 end;
 Edit1.text := inttostr(strtoint(edit1.text));
 Button1.Click;

end;

procedure TForm1.Edit3Change(Sender: TObject);
begin
 if (Edit3.text = '') or (Edit3.text = '0') then
 begin
 end
 else
 begin
 Edit3.text := inttostr(strtoint(edit3.text));
// if strtoint(edit7.text) < strtoint(Edit3.text) then
  Edit7.text := inttostr(round(strtoint(edit3.text)*2));
// if strtoint(edit8.text) < strtoint(Edit3.text) then
  Edit8.text := inttostr(round(strtoint(edit3.text)*2));

 Button1.Click;
 end;
end;

procedure TForm1.CheckBox1Click(Sender: TObject);
begin
 Button1.Click;

end;

procedure TForm1.CheckBox2Click(Sender: TObject);
begin
 Button1.Click;

end;

procedure TForm1.Edit4Change(Sender: TObject);
begin
 if edit4.text <> '' then Button1.Click;

end;

procedure TForm1.Edit7Change(Sender: TObject);
begin
 Button1.Click;

end;

procedure TForm1.Edit8Change(Sender: TObject);
begin
 Button1.Click;

end;

Procedure GetSize(Var C, X, Y: integer);
begin
  case C of
  0: begin X:=256;Y:=256; End;
  1: begin X:=512;Y:=256; End;
  2: begin X:=256;Y:=512; End;
  3: begin X:=512;Y:=512; End;
  4: begin X:=1024;Y:=512; End;
  5: begin X:=512;Y:=1024; End;
  6: begin X:=1024;Y:=1024; End;
  end;
end;

procedure TForm1.Button3Click(Sender: TObject);
Var X,Y, R, G, Xx, Yy, Tot, Smt, Off: integer;
    V, Sat: single;
    ExS: boolean;

begin
   Button5.Enabled := True;

   DrawFont(clWhite);

   ExS := Checkbox3.Checked;
   Off := Strtoint(edit5.text);
   Tot := Image1.Picture.Width*2;
   Smt := strtoint(Edit2.text);
   Sat := strtoint(Edit10.text)/100;

   ChangeTab(1);
   patblt(Image2.Picture.Bitmap.Canvas.Handle, 0, 0, Image2.Picture.Width, Image2.Picture.Height, BLACKNESS);
   Image2.Invalidate;

if Checkbox5.checked then
begin
   With Image2.canvas do
   For Y := 0 to Image1.Picture.Height do
   begin
   for X := 0 to Image1.Picture.Width do
   begin
     R := 0;G:=0;
     For Xx := X-Smt to X+Smt do
     For Yy := Y-Smt to Y+Smt do
     begin
       If (Xx > 0) and (XX < Image1.Picture.Width) then
       If (YY > 0) and (YY < Image1.Picture.Height) then
       begin
         if Not ExS then
         begin
           if (Abs(Xx-X) = abs(Yy-Y)) and (abs(Xx-X) > 0) then
           begin end
           else
           begin
            R := R + round(GetRValue(Image1.Canvas.Pixels[Xx,Yy])*Sat);
            Inc(G);
           end;
         end
         else
         begin
          R := R + round(GetRValue(Image1.Canvas.Pixels[Xx,Yy])*Sat);
          Inc(G);
         end;
         if (Checkbox4.checked) then
          if (G >= 5) and (R = 0) then begin break; end
         else
          if (G >= 9) and (R = 0) then break;
       end;
     end;
     if R > 5 then R := R div G;
     Pixels[X+Off, Y+Off] := RGB(R,R,R);
   end;
   if Y mod 32 = 0 then
   begin Image2.Invalidate;
    Application.ProcessMessages;
    Bar.Position := round(Y/Tot*100);
   end;
   if Button5.Enabled = false then begin exit; Bar.position := 0; end;
   end;
end;
   With Image2.canvas do
   for X := 0 to Image1.Picture.Width do
   begin
   For Y := 0 to Image1.Picture.Height do
   begin
      V := getGValue(Image1.canvas.pixels[X,Y]);
      V := V/257;
      if V >= 0.007782 then
      begin
       R := round(getRValue(Pixels[X,Y])*(1-V)+getRValue(Image1.canvas.Pixels[X,Y])*V);
       Pixels[X,Y] := rgb(r,r,r);
      end;
   end;
   if X mod 32 = 0 then
    begin Image2.Invalidate;
     Application.ProcessMessages;
     Bar.Position := round(X/Tot*100)+50;
    end;
   if Button5.Enabled = false then begin exit; Bar.position := 0; end;
   end;
   Bar.Position := 0;
   Button5.Enabled := False;
   DrawFont(Shape1.Brush.color);
end;


Procedure DrawTest;
Var X,Y,W, H, R, G, B, Tr,Tg,Tb: integer;
    CurX, CurY, Sx, Sy, Ex, Ey: integer;
    V: single;
    Stri: string;
begin

  With Form1.Image3.Picture.bitmap.Canvas do
  begin
     GetSize(CurSize, W, H);
     Brush.Color := rgb(100, 100, 100);
     Rectangle(0,0,W,H);
     Tr := GetRvalue(Pixels[1,1]);
     Tg := GetGvalue(Pixels[1,1]);
     Tb := GetBvalue(Pixels[1,1]);

     Curx := 3;
     Cury := 50;
     Stri := Form1.Edit12.Text;
   repeat

    if ord(Stri[1]) <> 32 then
    begin
     Sx := round(F[ord(Stri[1])-CharS].T1*W);
     Sy := round(F[ord(Stri[1])-CharS].U1*H);
     Ex := round(F[ord(Stri[1])-CharS].T2*W);
     Ey := round(F[ord(Stri[1])-CharS].U2*H);

     for X := Sx to Ex do
     Begin
     for Y := Sy to Ey do
     begin
        V := GetRValue(Form1.Image2.Canvas.Pixels[X,Y])/256;
        if V > 0.0077821011673151750972762645914397 then
        begin
         R := round(Tr*(1-V)+GetRValue(Form1.Image1.picture.bitmap.Canvas.Pixels[X,Y])*(V));
         G := round(Tg*(1-V)+GetGValue(Form1.Image1.picture.bitmap.Canvas.Pixels[X,Y])*(V));
         B := round(Tb*(1-V)+GetBValue(Form1.Image1.picture.bitmap.Canvas.Pixels[X,Y])*(V));
         Pixels[CurX+(X-Sx),CurY-(Ey-Y)] := RGB(r,g,b);
        end;
     end;

     if X mod 32 = 0 then
     begin
         form1.Bar.Position := round(X/W*100);
         form1.image3.Invalidate;
         application.ProcessMessages;
     end;
     end;

   CurX := CurX + round(F[ord(Stri[1])-CharS].W);
   end
   else
    CurX := curX + round(F[0].W);
   Stri := Copy(Stri, 2, length(Stri));
   until Stri = '';
  end;
  form1.Bar.Position := 0;
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
  DrawTest;
end;

procedure TForm1.TabChange(Sender: TObject);
begin
 ChangeTab(Tab.Tabindex);
end;



procedure TForm1.TrackBar1Change(Sender: TObject);
Var X, Y: integer;
begin
case Trackbar1.Position of
0:
Label4.caption := 'Texture Size: 256x256';
1:
Label4.caption := 'Texture Size: 512x256';
2:
Label4.caption := 'Texture Size: 256x512';
3:
Label4.caption := 'Texture Size: 512x512';
4:
Label4.caption := 'Texture Size: 1024x512';
5:
Label4.caption := 'Texture Size: 512x1024';
6:
Label4.caption := 'Texture Size: 1024x1024';
end;

   if CurSize <> Trackbar1.Position then
   begin
      CurSize := Trackbar1.Position;
      GetSize(CurSize, X,Y);
      Image1.Picture.Bitmap.Width := X;
      Image1.Picture.Bitmap.Height := y;
      Image2.Picture.Bitmap.Width := X;
      Image2.Picture.Bitmap.Height := y;
      patblt(Image1.Picture.Bitmap.Canvas.Handle, 0, 0, X, Y, BLACKNESS);
      patblt(Image2.Picture.Bitmap.Canvas.Handle, 0, 0, X, Y, BLACKNESS);
      Button1.Click;
   end;

end;


procedure TForm1.CheckBox5Click(Sender: TObject);
begin
  Groupbox2.Enabled := Checkbox5.checked;
  if not groupbox2.enabled then
  begin
    GroupBox2.Font.Color := ClBtnShadow;
  end
  else
  begin
    GroupBox2.Font.Color := ClBlack;
  end;
end;

procedure TForm1.Button5Click(Sender: TObject);
begin
  Button5.Enabled := False;
end;

procedure TForm1.Edit9Change(Sender: TObject);
begin
 if (Edit9.text = '') or (Edit9.text = '0') then
 begin
 end
 else
 begin
  CharS := strtoint(edit9.text);
  edit9.text := inttostr(Chars);
 end;
end;

procedure TForm1.Edit6Change(Sender: TObject);
begin
 if (Edit6.text = '') or (Edit6.text = '0') then
 begin
 end
 else
 begin
  CharE := strtoint(edit6.text);
  edit6.text := inttostr(CharE);
 end;

end;

procedure TForm1.Button6Click(Sender: TObject);
begin
 Messagebox(form1.handle, 'Font Studio 2'+#13#13+
 '(C) 2003 Michael Pote.'+#13#13+'Visit www.sulaco.co.za.', 'About Font Studio', MB_OK or MB_ICONINFORMATION);
 

end;

procedure TForm1.Shape1MouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
 if Colordialog1.Execute then
 begin
    Shape1.Brush.Color := colordialog1.Color;
    Button1.Click; 
 end;
end;

procedure TForm1.Edit11Change(Sender: TObject);
begin
   Button1.Click; Button4.Click;
end;

end.
