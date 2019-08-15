
void CSQC_Init(float apilevel, string enginename, float engineversion)
{
	Input_Init();
	Scene_Init();
}

void CSQC_WorldLoaded(){}

noref float CSQC_ConsoleCommand(string cmd){return TRUE;}

float CSQC_InputEvent(float evtype,float scanx,float chary,float devid){float i=Input_Manager(evtype,scanx,chary);return i;}

void CSQC_Input_Frame(){}

void CSQC_UpdateView(float vwidth, float vheight, float notmenu)
{
	clearscene();
	View_Update(vwidth,vheight);
	Input_Update();
	Ragdoll_Update();
	Scene_Update();
	renderscene();
	//post update
	UI_PostUpdate(vwidth,vheight);
}