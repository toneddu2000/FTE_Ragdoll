//from craFTEr - MIT licensed
void Ed_Cursor()
{
	local float gridsize = 2;
	
	if(inputCursor == TRUE){
		makevectors(input_angles);
		traceline(unproject([inputCursorOrigin_x, inputCursorOrigin_y, 0]), unproject([inputCursorOrigin_x, inputCursorOrigin_y, 300]), MOVE_EVERYTHING, sceneGizmo);
		//make sure cursor won't place at super top origins, when user touches header buttons
		if(inputCursorOrigin_y > (UI_HEADER_HEIGHT * 2)){
			inputCursor3dOrg = trace_endpos;
			//inputCursor3dOrg_x = -(trace_endpos_x / gridsize) * gridsize;
			//inputCursor3dOrg_y = floor(trace_endpos_y / gridsize) * gridsize;
			//inputCursor3dOrg_z = 128;
		}
		if(trace_ent.gameClass == GAME_CLASS_SCENECOLLISION){
			
		//position sceneGizmo
		setorigin(sceneGizmo,[inputCursor3dOrg_x,inputCursor3dOrg_y,inputCursor3dElevation]);
		setsize(sceneGizmo,sceneGizmo.mins,sceneGizmo.maxs);}
	}
}

float Input_Manager(float evtype, float scanx,float chary)
{
	switch(evtype){
		case IE_KEYDOWN:
			if (scanx == K_MOUSE1){
				if(doll){
					//TONEDDUFIXME:it doesn't work
					/*
					skel_build(doll.skeletonindex, doll, doll.modelindex,0,0,0);
					skel_ragupdate(doll,"animatebody root 0",doll.skeletonindex);
					skel_set_bone(doll.skeletonindex, 8, [0,0,300]);
					skel_build(doll.skeletonindex, doll, doll.modelindex,0,0,0);
					*/
					//Ragdoll_Dismemberment(doll,"jleg_r");
				}
			}
			else if (scanx == K_UPARROW){
				setorigin(sceneGizmo,[sceneGizmo.origin_x+=8,sceneGizmo.origin_y,sceneGizmo.origin_z]);
			}
			else if (scanx == K_DOWNARROW){
				setorigin(sceneGizmo,[sceneGizmo.origin_x-=8,sceneGizmo.origin_y,sceneGizmo.origin_z]);
			}
			else if (scanx == K_LEFTARROW){
				setorigin(sceneGizmo,[sceneGizmo.origin_x,sceneGizmo.origin_y+=8,sceneGizmo.origin_z]);
			}
			else if (scanx == K_RIGHTARROW){
				setorigin(sceneGizmo,[sceneGizmo.origin_x,sceneGizmo.origin_y-=8,sceneGizmo.origin_z]);
			}
		break;
		case IE_KEYUP:
			if (scanx == K_MOUSE1){
				Ragdoll_Spawn();
			}
			else if (scanx == K_MOUSE2){
				//Ragdoll_Reset(doll,"die");
				inputCursor = !inputCursor;
				setcursormode(inputCursor);
			}
			else if (scanx == K_RCTRL){
				//Ragdoll_Spawn();
			}
			else if (scanx == K_TAB){
				uiBoneNames = !uiBoneNames;
			}
			else if (scanx == K_SPACE){
				if(sceneNum < 3){
					sceneNum++;
				}
				else{
					sceneNum = 0;
				}
			}
			//LETTER A
			if(scanx == 97){
				ragdollAnimation = !ragdollAnimation;
			}
			//LETTER B
			if(scanx == 98){
				scenePureBSP = !scenePureBSP;
				cvar_set("scene_purebsp",ftos(scenePureBSP));
			}
			else if (scanx == K_ENTER){
				cvar_set("scene_num",ftos(sceneNum));
				localcmd("map game.map");
			}
			else if (scanx == K_MWHEELUP){
				if(inputCursor3dElevation < INPUT_CURSOR_3D_ELEVATION_MAX){
					inputCursor3dElevation += 8;
				}
			}
			else if (scanx == K_MWHEELDOWN){
				if(inputCursor3dElevation > 128){
					inputCursor3dElevation -= 8;
				}
			}
		break;
		case IE_MOUSEABS:
			inputCursorOrigin_x = scanx;
			inputCursorOrigin_y = chary;		
		return TRUE;
	}
	return 0;
}

void Input_Update(){Ed_Cursor();}

void Input_Init(){inputAngles=input_angles;inputCursor3dElevation=128;}