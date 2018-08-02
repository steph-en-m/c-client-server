#include "test.h"
//handles double
char *double_(char *cmd,int *s){
 char buf[1024]={"\0"},input[128]={"\0"},*ret=buf;
 int x,j=0,i;
 input[j]='\0';
 for(x=0;x<(int)strlen(cmd);x++)input[j++]=cmd[x];
 input[j]='\0';
 if(strlen(input)>=51){*s=0;return "Error: Command length exceeds 50 characters";}
 else if(strlen(input)<=1){*s=2;return "Blacklisted";}
 sprintf(ret,"%s\0",doubleword(input));
 i = (int)(strlen(input)*2);ret[i]='\0';
 *s = 1;
 return ret;
}

//handles reverse
char *reverse_(char *cmd,int *s){
 char buf[1024]={"\0"},input[128]={"\0"},*ret=buf;
 int x,j=0;
 input[j]='\0';
 for(x=0;x<(int)strlen(cmd);x++)input[j++]=cmd[x];
 input[j]='\0';
 if(strlen(input)>=51){*s=0;return "Error: Command length exceeds 50 characters";}
 else if(strlen(input)<=1){*s=2;return "Blacklisted";}

 sprintf(ret,"%s\0",reverse(input));
 *s = 1;
 return ret;
 }

            //handles replacement
char *replace_(char *cmd,int *s){
 char buf[1024]={"\0"},input[128]={"\0"},value[512]={"\0"},factor[512]={"\0"},*ret=buf;
 int x,j=0;
 input[j]='\0';
 for(x=0;x<(int)strlen(cmd);x++)input[j++]=cmd[x];
 input[j]='\0';
 if(strlen(input)>=51){*s=0;return "Error: Command length exceeds 50 characters.";}
 else if(strlen(input)<=0){*s=2;return "Blacklisted.";}
  sscanf(input,"%s%s",value,factor);
 sprintf(ret,"%s\0",replace(value,factor));
 *s=1;return ret;
}

    //handles deletion
char *delete_(char *cmd,int *s){
 char buf[1024]={"\0"},input[128]={"\0"},value[512]={"\0"},factor[512]={"\0"},*ret=buf;
 int x,j=0;
 input[j]='\0';
 for(x=0;x<(int)strlen(cmd);x++)input[j++]=cmd[x];
 input[j]='\0';
 if(strlen(input)>=51){*s=0;return "Error: Command length exceeds 50 characters.";}
 else if(strlen(input)<=1){*s=2;return "Blacklisted.";}
 sscanf(input,"%s%s",value,factor);
 sprintf(ret,"%s\0",delet(value,factor));
 *s=1;return ret;
}

//handles encrption

char *encrypt_(char *cmd,int *s){
 char buf[1024]={"\0"},input[128]={"\0"},*ret=buf;
 int x,j=0;
 input[j]='\0';
 for(x=0;x<(int)strlen(cmd);x++)input[j++]=cmd[x];
 input[j]='\0';
 if(strlen(input)>=51){*s=0;return "Error: Command length exceeds 50 characters";}
 else if(strlen(input)<=1){*s=2;return "Blacklisted.";}
 sprintf(ret,"%s\0",encrypt(input));
 *s=1;return ret;
}

//handles decryption

char *decrypt_(char *cmd,int *s){
 char buf[1024]={"\0"},input[128]={"\0"},*ret=buf;
 int x,j=0;
 input[j]='\0';
 for(x=0;x<(int)strlen(cmd);x++)input[j++]=cmd[x];
 input[j]='\0';
 if(strlen(input)>=51){*s=0; return "Error: Command length exceeds 50 characters";}
 else if(strlen(input)<=1){*s=2;return "Blacklisted.";}
 sprintf(ret,"%s\0",decrypt(input));
 *s=1;return ret;
}

//call command functions


char *doubleword(char *single){
char szEnc[1024]={"\0"},*ptr=szEnc;
	sprintf (ptr,"%s%s\0",single,single);
		return ptr;
}

char *reverse(char *unreverse){
	char ret[1024]={"\0"};
	char *ret2=ret;
	int i,j;
	for(i=0,j=((int)strlen(unreverse)-1);j>=0;j--){
		ret2[i++]=unreverse[j];
	}
	ret2[i]='\0';
	return ret2;
}
char *delet(char *input,char *condition){
	int i,error,p,s,k,pos[10];
	char szOut[128]={"\0"},*out=szOut;
	k=0;
	s=0;
	for(i=0;i<(int)strlen(condition);i++){
		if(condition[i]==','){
			out[s]='\0';
			sscanf(out,"%d",&pos[k]);
			k++;
			s=0;
			sprintf(out,"\0");
		}
		else if((int)(strlen(condition)-1)==i){
			out[s++]=condition[i];out[s]='\0';
			sscanf(out,"%d",&pos[k++]);
		}
		else {
			out[s++]=condition[i];
		}
	}

	s=0;
	for(i=0;i<(int)strlen(input);i++){
		error=0;
		for(p=0;p<k;p++){

			if(pos[p]==(i+1)){error = 1;}
		}
		if(!error){out[s++]=input[i];}
		}
	out[s]='\0';
	return out;
}

char *replace(char *input,char *condition){
	int i,error,p,s,k,pos[10],replacer[10];
	char szOut[128]={"\0"},*out=szOut,ch,sp,*ptr;
	k=0;
	s=0;
	for(i=0;i<(int)strlen(condition);i++){
		if(condition[i]==','){
			out[s]='\0';
			while((ptr=strpbrk(out,"-"))!=NULL)*ptr=' ';
			sscanf(out,"%d%c%c",&pos[k],&sp,&ch);
			replacer[k]=(int)ch;
			k++;
			s=0;
			sprintf(out,"\0");
		}
		else if((int)(strlen(condition)-1)==i){
			out[s++]=condition[i];out[s]='\0';
			while((ptr=strpbrk(out,"-"))!=NULL)*ptr=' ';
			sscanf(out,"%d%c%c",&pos[k],&sp,&ch);
			replacer[k++]=(int)ch;
		}
		else {
			out[s++]=condition[i];
		}
	}

	s=0;
	for(i=0;i<(int)strlen(input);i++){
		error=0;
		for(p=0;p<k;p++){

			if(pos[p]==(i+1)){error = 1;out[s++]=(unsigned char)replacer[p];}
		}
		if(!error){out[s++]=input[i];}
		}
	out[s]='\0';
	return out;
}
//start encryption functions here
int char_encrypt(unsigned char value){

	static int status =0;
	int i;
	static char alphabet[512]={"\0"};
	if(!status){
		sprintf(alphabet,"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789.;%@/\\+_-?\'\" |#[]{}!`~\0");
		status++;
	}
	for(i=0;i<(int)strlen(alphabet);i++)
	if(alphabet[i]==value)break;
	return i+1;

}

int return_caps(unsigned char small){
	return char_encrypt((unsigned char)toupper(small));
}

unsigned char return_char(int position){
	static int status =0;
	static char alphabet[512]={"\0"};
	if(!status){
		sprintf(alphabet,"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789.;%@/\\+_-?\'\" |#[]{}!`~\0");
		status++;
	}
	if((position-1)>=(int)strlen(alphabet)){
		return '\0';
	}
	else{
		return alphabet[position-1];
	}
}

int return_low(unsigned char upper){
	return char_encrypt((unsigned char)tolower(upper));
}

char *encod(unsigned char chal){
	char szRet[1024]={"\0"},*ret=szRet,out[1024]={"\0"},swap[1024]={"\0"};
	int x,space,i,j;
	x=char_encrypt(chal);
	if(x<=9){
		x=return_caps(chal);
		sprintf(ret,"%d\0",x);
		return ret;
	}
	sprintf(out,"%d\0",x);
	sprintf(ret,"%c %c\0",out[0],out[1]);
	space=1;
	sprintf(swap,"%s\0",ret);
	while(x>9){
		x=x-1;
		ret[space]=return_char(return_low(return_char(x)));
		space++;
		x=(x+1)-9;
		if(x<=9){
			sprintf(swap,"%s\0",ret);
			ret[space]=return_char(return_caps(return_char(x)));
			for(i=space;i<(int)strlen(swap);i++){
				ret[space+1]=swap[i];space++;
			}
		}
		else{
			sprintf(swap,"%s\0",ret);
			sprintf(out,"%d\0",x);
			ret[space]=out[0];
			ret[space+1]=' ';
			ret[space+2]=out[1];
			for(i=space,j=space+3;i<(int)strlen(swap);i++){
				ret[j++]=swap[i];
			}
			//printf("\n ret=%s swap=%s swap[%d]=%c\n",ret,swap,i,swap[i-1]);
			space=space+1;
			sprintf(swap,"%s\0",ret);
		}
	}
	ret[space+1]='\0';
	return ret;
}
char *encrypt(const char *str)
{
	char szRet[1024]={"\0"};
	char *ret=szRet;
	int i;
	for(i=0;i<(int)strlen(str);i++){
		if(i==0){
			sprintf(ret,"%s \0",encod(str[i]));
		}
		else{
			strcat(ret,encod(str[i]));
			strcat(ret," ");
		}
	}
	strcat(ret,"\0");

	return ret;
}
unsigned char decod(char *str){
	int x;
	char out[128]={"\0"};

	if(strlen(str)<=2){
		sscanf(str,"%d",&x);
		return return_char(return_low(return_char(x)));
	}
	sprintf(out,"%c%c\0",str[0],str[(int)(strlen(str)-1)]);
	sscanf(out,"%d",&x);
	return return_char(x);
}

char *decrypt(char *str){
int j,s,i;
char szRet[1024]={"\0"},*ret=szRet,out[128]={"\0"};
j=0;s=0;
for(i=0;i<(int)(strlen(str)-1);i++){
	if(str[i]==' '){
		out[s]='\0';
		ret[j++]=decod(out);
		s=0;
		out[s]='\0';
			}
	else if(i==(int)(strlen(str)-2)){
		out[s++]=str[i];out[s++]=str[i+1];
		out[s]='\0';
		ret[j++]=decod(out);
	}
	else {
		out[s++]=str[i];
	}

}
ret[j]='\0';

return ret;
}

void getBody(int i,char *cmd,DST *out){
 char input[128]={"\0"},*in=input;
 int x,j=0;
 input[j]='\0';
 for(x=i+1;x<(int)strlen(cmd);x++)in[j++]=cmd[x];
 in[j]='\0';
 sprintf(out->out,"%s\0",in);
 return;
}

