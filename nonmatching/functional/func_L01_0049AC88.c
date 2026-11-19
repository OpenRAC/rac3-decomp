/* functional: high. PAL constants: pad scale 0.02 and zoom factor 1.2 (NTSC draft used 1/60); rotation/zoom blocks read against the asm; 0x910/4/8 are pad bits; start time estimated; float literals compile via .sdata not mtc1 so bytes differ */
typedef struct { char pad[0x144]; float axis0,axis1,axis2; char p[0x74]; int buttons; } Input;
typedef struct { char pad[0x24]; char *model; char p28[4]; float scale; char p30[0xc0]; float x,y,z; } Obj;
typedef struct { int a,b,mode,text; } Row;
extern Obj *D_001D9340_sda[1];
extern int D_001D9380_sda;
__asm__(".extern D_001D9380_sda, 4");
extern int D_001D9384_sda;
__asm__(".extern D_001D9384_sda, 4");
extern float D_001D93D4_sda;
__asm__(".extern D_001D93D4_sda, 4");
extern float D_001D93D8_sda;
__asm__(".extern D_001D93D8_sda, 4");
extern float D_001D93DC_sda;
__asm__(".extern D_001D93DC_sda, 4");
extern float D_001D93D0_sda;
__asm__(".extern D_001D93D0_sda, 4");
extern float D_001D93C0_sda;
__asm__(".extern D_001D93C0_sda, 4");
extern float D_001D93C4_sda;
__asm__(".extern D_001D93C4_sda, 4");
extern float D_001D93CC_sda;
__asm__(".extern D_001D93CC_sda, 4");
extern Row D_L01_002EBDE8[];
extern int func_L01_0047EBE0(void);
extern void func_L01_00517748(int),func_L01_00516090(void*);
extern int func_L01_0049B428(int),func_L01_0049B490(int);
extern float func_0040F3F8(float,float),func_0040F440(float,float);
extern void *func_0041A878(int);
#define IN ((Input*)D_001D52FC[0])
void func_L01_0049AC88(void *arg) {
 Obj *o; float v,max,scale,r;
 if(IN->buttons&0x910) { func_L01_00517748(func_L01_0047EBE0());func_L01_00516090(arg); }
 if(IN->buttons&4) { D_001D9380_sda=D_001D9384_sda;D_001D9384_sda=func_L01_0049B428(D_001D9384_sda); }
 else if(IN->buttons&8) { D_001D9380_sda=D_001D9384_sda;D_001D9384_sda=func_L01_0049B490(D_001D9384_sda); }
 if(D_001D9384_sda!=-1) {
 o=D_001D9340_sda[D_001D9384_sda];
 if(o) {
 if(D_L01_002EBDE8[D_001D9384_sda].mode==0) {
 o->x=func_0040F3F8(o->x,IN->axis1*(-(D_001D93D4_sda*0.017453292f*0.02f)));
 v=func_0040F440(o->y,1.57079637f);
 v=func_0040F3F8(v,IN->axis2*(-D_001D93D8_sda*0.017453292f*0.02f));
 max=D_001D93DC_sda*0.017453292f; if(v>max)v=max;else if(v< -max)v= -max;
 o->y=func_0040F3F8(1.57079637f,v);
 scale=*(float*)(o->model+36);r=o->scale/scale+IN->axis0*(-D_001D93D0_sda*1.2f);
 if(r>D_001D93C4_sda)r=D_001D93C4_sda;if(r<D_001D93C0_sda)r=D_001D93C0_sda;o->scale=scale*r;
 } else {
 o->z=func_0040F3F8(o->z,IN->axis1*(D_001D93D4_sda*0.017453292f*0.02f));
 o->y=func_0040F3F8(o->y,IN->axis2*(-D_001D93D8_sda*0.017453292f*0.02f));
 max=D_001D93DC_sda*0.017453292f;if(o->y>max)o->y=max;else if(o->y< -max)o->y= -max;
 scale=*(float*)(o->model+36)*D_001D93CC_sda;r=o->scale/scale+IN->axis0*(-D_001D93D0_sda*1.2f);
 if(r>D_001D93C4_sda)r=D_001D93C4_sda;if(r<D_001D93C0_sda)r=D_001D93C0_sda;o->scale=scale*r;
 }
 }
 func_L01_00516FD8(0x4d0003,(s32)func_0041A878(D_L01_002EBDE8[D_001D9384_sda].text));func_L01_00516D60(0x4d0003,1);
 } else func_L01_00516D60(0x4d0003,0);
}
