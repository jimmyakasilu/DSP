#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void reverse(float* arr1,float* arr2,int lh){
	int i,j;
	for(i=0,j=lh-1;i<lh;i++,j--){
			arr2[j]=arr1[i];}
}
int largest(int* arr,int ly){
	int i;
	int l = arr[0];
	printf("\n\nl = %d",l);
	for(i=0;i<ly;i++){
		if(arr[i]>l){
			l = arr[i];}}
	return l;
}
float smallest(float* arr,int ly){
	int i;
	float s=1000000;
	printf("\n\ns: %.2f", s);
	for(i=0;i<ly;i++){
		if(arr[i]<s && arr[i]!=0){
			s = arr[i];}}
	return s;
}
void main()
{
	float a,s,q,*h,*hr,ylim2;
	char f;
	int i,j,k,li,lh,ly,lx,maxval,xlim,ylim;
	printf("Press\n e for exponential\n u for unit step\n r for random\n");
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<1ST FUNCTION
	printf("\n\nEnter the 1st function: \n");
	printf("\nEnter type of function: \n");
	scanf("%c",&f);
	printf("Enter length of function: \n");
	scanf("%d",&li);
	float x[li];
	if (f=='e'){
		printf("Enter base value: \n");
		scanf("%f",&a);
		for (i=0;i<li;i++){
			x[i] = powf(a,i);
		}}
	else if(f=='u'){
		for (i=0;i<li;i++){
			x[i] = 1;
		}}
	else{
		for (i=0;i<li;i++){
			printf("Enter input value at position %d: \n",i);
			scanf("%f",&q);
			x[i]=q;
		}}
	printf("\nx[n]: \n");
	for(i=0;i<li;i++){
		printf("%.2f ",x[i]);}
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<2ND FUNCTION
	fflush(stdin);
	printf("\n\nEnter the 2nd function: \n");
	printf("\n\nEnter the type of function: \n");
	scanf("%c",&f);
	printf("Enter length of function: \n");
	scanf("%d",&lh);
	h=(float*)malloc(lh*sizeof(float));
	if (f=='e'){
		printf("Enter base value: \n");
		scanf("%f",&a);
		for (i=0;i<lh;i++){
			h[i] = powf(a,i);
		}}
	else if(f=='u'){
		for (i=0;i<lh;i++){
			h[i] = 1;
		}}
	else{
		for (i=0;i<lh;i++){
			printf("Enter input value at position %d: \n",i);
			scanf("%f",&q);
			h[i]=q;
		}}
	printf("\nh[n]: \n");
	for(i=0;i<lh;i++){
		printf("%.2f ",h[i]);}
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<TAKING THE REFLECTION
	hr = (float*)malloc(lh*sizeof(float));
	/*for(i=0,j=lh-1;i<lh;i++,j--){
			hr[j]=h[i];}*/
	reverse(&h[0],&hr[0],lh);
	printf("\n\nhr[n]: \n");
	for(i=0;i<lh;i++){
		printf("%.2f ",hr[i]);}
	//PADDING ZEROS
	lx = li+lh-1;
	float x2[lx];
	for(i=0;i<lh-1;i++){
		x2[i]=0;}
	for(i=0;i<li;i++){
		x2[i+lh-1]=x[i];}
	for(i=0;i<lh-1;i++){
		x2[i+lh+li-1]=0;}
	/*printf("\n\npadded x[n]: \n");
	for(i=0;i<2*lh+li-2;i++)
	{printf("%.4f ",x2[i]);}*/
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<CONVOLUTION
	ly=lh+li-1;
	float y2[ly], y[ly];
	int yg[ly];
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<CONVOLVING THE TWO FUNCTIONS
	printf("\n\ny[n]: \n");
	for(i=0;i<ly;i++){
		y2[i]=0;
		y[i]=0;
		for(j=0;j<lh;j++){
			y2[i]=y2[i]+x2[j+i]*hr[j];}
		y[i]=y2[i]*100;
		printf("%.2f ",y[i]);}
	s = smallest(&y,ly);
	printf("\n\nsmallest: %.2f\n",s);
	printf("\n\nyg[n]: \n");
	for(i=0;i<ly;i++){
		y[i]=y[i]/s;
		printf("%.2f\n",y[i]);
		yg[i]=(int)round(y[i]);
		printf("%d\n",yg[i]);}
	FILE *file = fopen("C:\\Users\\Siladittya\\Desktop\\ConvolvedData.txt","w");
	if(file == NULL){
		printf("Error opening File\n\n");
		exit(1);}
	for(i=0;i<ly;i++){
		fprintf(file,"%.2f ",y2[i]);}
	fclose(file);
	char command[50] = "python C:\\Python27\\DSP\\ConvolutionPlot.py";
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<graph
	maxval = largest(&yg,ly);
	ylim2 = maxval+1;
	ylim = (int)((round(ylim2/10))*10);
	xlim = 2*ly+1;
	printf("\n\n%f %d %d",ylim2,ylim,xlim);
	printf("\n\n");
	for(j=ylim+1;j>=0;j--){
		for(i=0;i<xlim;i++){
			if(i==0 && (j-1)%5==0){
				printf("%d",j-1);}
			else if(i==0 && (j-1)%5!=0){
				printf(" ");}
			if(i>0 && j>0 && (i%2==0) && yg[(i-2)/2]>=j-1)
				{printf("|");}
			else{
				if(j==0){
					for(i=0;i<xlim;i++){
						if(i%2==0 && i>0){
							printf("%d",(i-2)/2);}
						else{
							printf(" ");}}
					printf("\n\tDiscrete Time Intervals\t\n");}
				else{
				printf(" ");}}}
		printf("\n");}
	system(command);}
