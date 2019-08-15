void View_Update(float w,float h)
{
	setviewprop(VF_ORIGIN,CAMERA_ORIGIN_OFFSET);
	setviewprop(VF_ANGLES,[0,30,0]);
	if(inputCursor == FALSE){
		inputAngles = input_angles;
		setviewprop(VF_ANGLES,inputAngles);
	}
	else{
		setviewprop(VF_ANGLES,inputAngles);
	}
}