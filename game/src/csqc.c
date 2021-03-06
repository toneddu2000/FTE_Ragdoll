/*
MIT License

Copyright (c) 2018 Antonio "toneddu2000" Latronico

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

entity ropelike;

void CSQC_Init(float apilevel, string enginename, float engineversion)
{
	Input_Init();
	Scene_Init();
	ropelike = spawn();
	setorigin(ropelike,[100,100,1024]);
	precache_model("models/ropelike.iqm");
	setmodel(ropelike,"models/ropelike.iqm");
	ropelike.solid = SOLID_SLIDEBOX;
	ropelike.forceshader = shaderforname ("checker1");
	setsize(ropelike,ropelike.mins,ropelike.maxs);
	Ragdoll_Create(ropelike);
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
	if(ropelike){
		
		skel_build(ropelike.skeletonindex,ropelike,ropelike.modelindex,0,0,0,1);
		ropelike.frame = 0;
		ropelike.frame1time += frametime * 1.5;
		//skel_ragupdate(ropelike,"animatebody b0 1",ropelike.skeletonindex);
		//skel_ragupdate(ropelike,"animatebody b1 0.7",ropelike.skeletonindex);
		//skel_ragupdate(ropelike,"animatebody b2 0.3",ropelike.skeletonindex);
		//skel_ragupdate(ropelike,"animatebody b3 0",ropelike.skeletonindex);
		skel_ragupdate(ropelike,"doll models/ropelike.iqm.doll",0);
		addentity(ropelike);
	}
	renderscene();
	//post update
	UI_PostUpdate(vwidth,vheight);
	Ragdoll_PrintBoneNames(ropelike);
}