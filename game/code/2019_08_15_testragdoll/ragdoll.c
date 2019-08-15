void Ragdoll_Think()
{
	if(!self.ragdollActive){
		makevectors(world.angles);
		//simple gravity
		traceline(self.origin,self.origin+(-v_up*8),0,self);
		if(trace_fraction >=1){
			self.velocity = -v_up;
			self.velocity *= 4;
			tracebox(self.origin,self.mins,self.maxs,self.origin+self.velocity,0,self);
			setorigin(self,trace_endpos);
			setsize(self,self.mins,self.maxs);
			self.ragdollOnGround = FALSE;
		}
		else{
			self.ragdollOnGround = TRUE;
		}
	}
	self.nextthink = time + GAME_THINK_REFRESH;
	self.think = Ragdoll_Think;
}

void Ragdoll_PrintBoneNames(entity e)
{
	if(uiBoneNames){
		local float f,y=60;
		drawstring([10,y-20,0],"Ragdoll bone names:",[8,8,0],[1,1,1], 1, 0);
		for(f=0;f<skel_get_numbones(e.skeletonindex)+1;f++){
			local string s = strcat("bone #: ",ftos(f)," name: ",skel_get_bonename(e.skeletonindex,f));
			drawstring([10,y,0],s,[6,6,0],[1,1,1], 1, 0);
			y+=15;
		}
	}
}

void Ragdoll_Dismemberment(entity e,string bonename)
{
	if(e){
		skel_ragupdate(e,strcat("enablejoint ",bonename," 0"),e.skeletonindex);
		//skel_build(e.skeletonindex, e, e.modelindex,0,0,0);
	}
}

void Ragdoll_Execute(entity e, string framename, float speed)
{
	e.frame = frameforname(e.modelindex, framename);
	local float duratdie = frameduration(e.modelindex,e.frame);
	if(!e.ragdollActive && e.ragdollOnGround){
		if(e.frame1time < duratdie){
			e.frame1time += frametime * speed;
		}
		else{
			e.ragdollActive = TRUE;
		}
	}
	if(e.ragdollActive){
		skel_build(e.skeletonindex, e, e.modelindex,0,0,0);
		skel_ragupdate(e,"animate 1",e.skeletonindex);
		skel_ragupdate(e,strcat("doll ",e.model,".doll"),e.skeletonindex);
	}
	else{
		skel_build(e.skeletonindex, e, e.modelindex,0,0,0);
		skel_ragupdate(e,"animate 0",e.skeletonindex);
	}
}

void Ragdoll_Update()
{
	local entity e;
	
	e = world;
	//cycle trough all the ui entities finding the one which is in the correct hover position while mouse button is clicking
	while ((e = nextent(e))){
		if(e.gameClass == GAME_CLASS_DOLL){
			addentity(e);
			Ragdoll_Execute(e,strcat("die",ftos(e.ragdollDieAnimation)),0.5);
		}
	}
}

void Ragdoll_Reset(entity e, string framename)
{
	e.ragdollActive = FALSE;
	e.frame = frameforname(e.modelindex,framename);
	e.frame1time = 0;
	skel_build(e.skeletonindex, e, e.modelindex,0,0,0);
	skel_ragupdate(e,"cleardoll",e.skeletonindex);
}

void Ragdoll_Create(entity e)
{
	if (!e.skeletonindex){
		e.skeletonindex = skel_create(e.modelindex);
		skel_build(e.skeletonindex, e, e.modelindex,0,0,0);
	}
}

void Ragdoll_Spawn()
{
	//create doll model and apply ragdoll to it
	doll = spawn();
	setorigin(doll,sceneGizmo.origin);
	doll.gameClass = GAME_CLASS_DOLL;
	doll.ragdollOnGround = FALSE;
	if(ragdollAnimation){
		doll.ragdollActive = FALSE;
	}
	else{
		doll.ragdollActive = TRUE;
	}
	doll.ragdollDieAnimation = rint(random(2));
	setmodel(doll,"models/ragtest2.iqm");
	Ragdoll_Create(doll);
	doll.forceshader = shaderforname ("checker1");
	doll.solid = SOLID_NOT;
	setsize(doll,doll.mins,doll.maxs);
	doll.nextthink = GAME_THINK_REFRESH;
	doll.think = Ragdoll_Think;
	ragdollCurrent = doll;
}