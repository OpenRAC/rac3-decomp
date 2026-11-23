/* functional: high. Ported from the NTSC-U draft and rewritten against PAL asm: PAL names, (r*5+2)/6 on the third argument, gp global at 0x1DD8E8; compiles, bytes differ in frame size (0xF0 vs 0xE0, locals a/b/c) only. Particle burst around spots in scratchpad list, plus hit events on nearby objects. */
typedef int Q __attribute__((mode(TI)));
typedef struct {float x,y,z,w;} __attribute__((aligned(16))) V;
extern unsigned char D_L19_0021EED8[], D_L19_001D66F0[];
extern unsigned char *D_L19_001ECEC0[];
extern V D_L19_70000000[];
extern int D_001DD8E8;
extern int func_003C2B88(void*,int);
extern void func_00382580(float,float,void*);
extern float func_L01_00443A18(float,float),func_003824E0(float,float);
extern int func_00382498(int,int);
extern unsigned char *func_L01_004713C8(void*,void*,int,int,int,int,int,int,float,float,float);
extern void func_0038CDF8(float,void*,void*,void*);
extern int func_003D4D00(float,void*,int,void*,int);
extern int func_00382348(void*);
extern void func_0038CF68(float,void*,void*);
extern void func_L01_00446760(float,void*,void*,int,void*);
extern void func_L01_00446978(void*,void*);
extern void func_003C4138(float,float,void*);
extern void func_L01_00404A10(void*,void*);
extern void func_L19_0035D7D0(void);
void func_L19_0035D2B8(unsigned char *m,int *colors){
V a,b,c;
unsigned char hit[48] __attribute__((aligned(16)));
V *v=D_L19_70000000;
unsigned char *fx,*obj,**list;
int count,i,n,r;
float scale;
count=func_003C2B88(*(void**)((unsigned char*)&D_001A4BE0+0x25c0),0);
if(count)for(i=count;i>0;i--,v+=2){
if(v[1].w==0.0f){
a=*v;a.w=1.0f;
func_00382580(0.0f,v->w,&b);
__asm__("lqc2 $vf2, %1
	lqc2 $vf1, %2
	vadd.xyz $vf2, $vf2, $vf1
	sqc2 $vf2, %0" : "=m"(a) : "m"(a),"m"(b) : "vf1","vf2");
n=(int)func_L01_00443A18(2.0f,5.0f);
scale=func_003824E0(0.7f,1.0f)*v->w;
r=func_00382498(10,15);
func_L01_004713C8(&a,D_L19_001D66F0,(r*5+2)/6,colors[0],n,127,127,1,scale*210000.0f,2100.0f,-0.000833333354f);
n=-(n*2);
r=func_00382498(10,15);
scale*=6.0f;
fx=func_L01_004713C8(&a,D_L19_001D66F0,(r*5+2)/6,colors[1],n,48,48,0,scale*210000.0f,4200.0f,-0.000833333354f);
}else{
a=*v;b=v[1];a.w=1.0f;b.w=1.0f;
scale=func_003824E0(0.0f,1.0f);
func_0038CDF8(scale,&c,&a,&b);
c.x+=func_003824E0(-v->w*0.4f,v->w*0.4f);
c.y+=func_003824E0(-v->w*0.4f,v->w*0.4f);
c.z+=func_003824E0(-v->w*0.4f,v->w*0.4f);
n=(int)func_L01_00443A18(2.0f,5.0f);
scale=func_003824E0(0.7f,1.0f)*v->w;
r=func_00382498(10,15);
func_L01_004713C8(&c,D_L19_001D66F0,(r*5+2)/6,colors[0],n,127,127,1,scale*210000.0f,2100.0f,-0.000833333354f);
n=-(n*2);r=func_00382498(10,15);scale*=6.0f;
fx=func_L01_004713C8(&c,D_L19_001D66F0,(r*5+2)/6,colors[1],n,48,48,0,scale*210000.0f,4200.0f,-0.000833333354f);
}
if(fx)fx[2]=**(unsigned char**)(D_L19_0021EED8+0xd4);
}
if(D_001DD8E8==2){
float *radius=(float*)(*(unsigned char**)(m+0x68)+0x2c);
count=func_003D4D00(*radius*0.5f,m+0x10,0,m,0);
if(count>0)for(list=D_L19_001ECEC0,i=count;i;i--,list++){
obj=*list;
if((func_00382348(obj)||(*(unsigned short*)(obj+0x34)&0x4000))&&obj!=*(unsigned char**)((unsigned char*)&D_001A4BE0+0x25c0)){
__asm__("lqc2 $vf2, %1
	lqc2 $vf1, %2
	vsub.xyz $vf2, $vf2, $vf1
	sqc2 $vf2, %0" : "=m"(a) : "m"(*(V*)(obj+0x10)),"m"(*(V*)((unsigned char*)&D_001A4BE0+0xe0)) : "vf1","vf2");
func_0038CF68(2.0f,&a,&a);
func_L01_00446760(2.0f,hit,m,0x410000,&a);
*(Q*)hit=*(Q*)&a;
*(int*)(hit+0x20)=1;*(float*)(hit+0xc)=5627.9248f;
hit[0x18]=10;hit[0x19]=3;
*(unsigned short*)(hit+0x1a)=*(unsigned short*)(obj+0xaa);
*(void**)(hit+0x10)=m;
func_L01_00446978(obj,hit);
}}
func_003C4138(16.0f,0.266666681f,radius);
}
func_L01_00404A10(func_L19_0035D7D0,m);
}
