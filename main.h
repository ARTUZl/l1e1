//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelTrianglePoints;
	TImage *background;
	TPaintBox *PaintBox;
	TLabel *labelPointA;
	TEdit *xCoordA;
	TLabel *labelCoordX_A;
	TLabel *labelCoordY_A;
	TEdit *yCoordA;
	TLabel *labelPointB;
	TLabel *labelCoordX_B;
	TEdit *xCoordB;
	TLabel *labelCoordY_B;
	TEdit *yCoordB;
	TLabel *labelPointC;
	TLabel *labelCoordX_C;
	TEdit *xCoordC;
	TLabel *labelCoordY_C;
	TEdit *yCoordC;
	TButton *SaveTrianglePoints;
	TComboBox *ComboBox;
	TPanel *PanelTriangleCenter;
	TLabel *labelSetCenter;
	TLabel *labelCoordCenterX;
	TLabel *labelCoordCenterY;
	TEdit *xCoordCenter;
	TEdit *yCoordCenter;
	TButton *SaveCenterPoint;
	TTimer *TimerTop;
	TButton *top;
	TButton *stop;
	TTimer *TimerBottom;
	TButton *bottom;
	TPanel *PanelAction;
	TLabel *LabelActions;
	TButton *left;
	TButton *right;
	TTimer *TimerLeft;
	TTimer *TimerRight;
	TTimer *TimerRotateLeft;
	TTimer *TimerRotateRight;
	TButton *rotateRight;
	TButton *rotateLeft;
	TPanel *PanelCircleRadius;
	TLabel *LabelSetRadius;
	TLabel *LabelRadius;
	TEdit *circleRadius;
	TButton *saveRadius;
	TPanel *PanelCircleCenter;
	TLabel *LabelSetCenterCircle;
	TLabel *LabelCirclexCoordCenter;
	TEdit *xCoordCenterCircle;
	TLabel *LabelCircleyCoordCenter;
	TEdit *yCoordCenterCircle;
	TButton *SaveCenterCircle;
	TPanel *PanelInfo;
	TLabel *LabelInformation;
	TLabel *LabelInfoText;
	TTimer *TimerSizeL;
	TTimer *TimerSizeS;
	TLabel *LabelSize;
	TButton *sizeL;
	TButton *sizeS;
	TPanel *PanelPolygonPoints;
	TLabel *LabelSetPolygonPoints;
	TLabel *LabelChoosePoint;
	TComboBox *choosePoint;
	TLabel *LabelPointPA;
	TEdit *xCoordPA;
	TLabel *LabelyCoordPY;
	TEdit *yCoordPA;
	TButton *SavePolygonPoints;
	TLabel *LabelPointPE;
	TEdit *xCoordPB;
	TEdit *yCoordPB;
	TLabel *LabelPointPD;
	TEdit *xCoordPC;
	TEdit *yCoordPC;
	TLabel *LabelPointPC;
	TEdit *xCoordPD;
	TEdit *yCoordPD;
	TLabel *LabelPointPB;
	TEdit *xCoordPE;
	TEdit *yCoordPE;
	TLabel *LabelCoordPX;
	TPanel *PanelPolygonCenter;
	TLabel *LabelSetCoordsCenter;
	TButton *SaveCenterPolygon;
	TLabel *LabelxCenterPolygon;
	TEdit *xCenterPolygon;
	TLabel *LabelyCenterPolygon;
	TEdit *yCenterPolygon;
	TLabel *LabelDesigner;
	void __fastcall SaveClick(TObject *Sender);
	void __fastcall SaveTrianglePointsClick(TObject *Sender);
	void __fastcall SaveCenterPointClick(TObject *Sender);
	void __fastcall TimerTopTimer(TObject *Sender);
	void __fastcall topClick(TObject *Sender);
	void __fastcall stopClick(TObject *Sender);
	void __fastcall TimerBottomTimer(TObject *Sender);
	void __fastcall bottomClick(TObject *Sender);
	void __fastcall leftClick(TObject *Sender);
	void __fastcall TimerLeftTimer(TObject *Sender);
	void __fastcall TimerRightTimer(TObject *Sender);
	void __fastcall rightClick(TObject *Sender);
	void __fastcall TimerRotateLeftTimer(TObject *Sender);
	void __fastcall rotateRightClick(TObject *Sender);
	void __fastcall ComboBoxSelect(TObject *Sender);
	void __fastcall TimerRotateRightTimer(TObject *Sender);
	void __fastcall rotateLeftClick(TObject *Sender);
	void __fastcall saveRadiusClick(TObject *Sender);
	void __fastcall SaveCenterCircleClick(TObject *Sender);
	void __fastcall TimerSizeLTimer(TObject *Sender);
	void __fastcall TimerSizeSTimer(TObject *Sender);
	void __fastcall sizeLClick(TObject *Sender);
	void __fastcall sizeSClick(TObject *Sender);
	void __fastcall choosePointSelect(TObject *Sender);
	void __fastcall SavePolygonPointsClick(TObject *Sender);
	void __fastcall SaveCenterPolygonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
