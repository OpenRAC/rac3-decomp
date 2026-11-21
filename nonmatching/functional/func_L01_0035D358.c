/* functional: high. VU0 vsub/vadd as plain float ops (w unused); draft's inline asm dropped, all constants, colours and call args checked with the asm. */
typedef struct Player_0035D358 { u8 pad[0x2F];u8 index; } Player_0035D358;
typedef struct Row_0035D358 { u8 pad0;u8 type;u8 pad2[0xEE]; } Row_0035D358;
typedef struct Textures_0035D358 { u8 pad[0x184];u8 *data; } Textures_0035D358;
extern Player_0035D358 D_001425C0[];
extern Row_0035D358 D_L01_002C5600[];
extern Textures_0035D358 D_L01_00221098[];
extern u8 *D_L01_0022116C[];
extern f32 D_001A4EC0[];
extern f32 func_0038CEA8(void *);
void func_L01_0035D358(u8 *m, s128 *a, s128 *b)
{
 extern f32 func_003824E0(f32,f32);
 extern void func_0038CF68(void *,void *,f32);
 extern f32 func_L01_00443A18(f32,f32);
 extern void func_0038CE20(f32 *,f32 *,f32);
 extern s32 func_00382498(s32,s32);
 extern s32 func_0013D3E0(void);
 extern void func_L01_004CAB30(void *,void *);
 extern u8 *func_L01_0046A610(void *,void *,s32,s32,u32,s32,f32,f32,f32,f32,f32);
 extern s32 func_00382468(s32);
 extern void func_003C4C18(void *,f32);
 extern u8 *func_L01_00465738(void *,void *,u32,s32,s32,s32,s32,s32,s32,f32);
 S_38C110v to,from,velocity,pos,step,up;
 f32 *vars=*(f32 **)(m+0x68);
 f32 length;
 s32 count,i,spin,life,alpha;
 u32 colour;
 u8 *particle;
 *(s128 *)&to=*a;
 *(s128 *)&from=*b;
 if (!vars) return;
 length=func_0038CEA8(vars);
 count=(s32)(length/0.1f);
 *(s128 *)&pos=*(s128 *)&from;
 step.x=to.x-from.x; step.y=to.y-from.y; step.z=to.z-from.z; step.w=to.w;
 func_0038CF68(&step,&step,length/(f32)count);
 for(i=0;i<count;i++) {
  spin=(s32)func_L01_00443A18(1.0f,3.0f);
  func_0038CE20((f32 *)&velocity,D_001A4EC0,-(func_003824E0(0.1f,0.3f)*0.020000001f));
  life=func_00382498(3,6);
  if (func_0013D3E0()&2) {alpha=0x40;colour=0x00407FFF;}
  else {alpha=0x60;colour=0x004040FF;}
  switch (D_L01_002C5600[D_001425C0[0].index].type) {
   case 0: colour=0x00107F7F;break;
   case 2:case 3: colour=0x001010AF;break;
  }
  func_L01_004CAB30(&velocity,&velocity);
  particle=func_L01_0046A610(&pos,&velocity,(life*5+2)/6,alpha,colour,spin,42000.0f,1000.0f,1.0f,0.0f,0.0f);
  pos.x+=step.x; pos.y+=step.y; pos.z+=step.z;
  if (particle) {
   if (func_00382468(2)) particle[2]=D_L01_00221098[0].data[4];
   else particle[2]=D_L01_00221098[0].data[5];
   if (alpha==0x40) particle[3]=0x48;
   else particle[3]=0x44;
  }
 }
 if (D_L01_002C5600[D_001425C0[0].index].type) {
  u8 *particle;
  S_38C110v *v=&up;
  func_0038CE20((f32 *)&up,vars,-0.040000003f);
  func_003C4C18(v,0.12000000476837158f);
  up.z+=0.06000000238418579f;
  colour=0x7F80DFFF;
  if (func_00382468(2)) colour=0x7F407FFF;
  {
   s32 type=D_L01_002C5600[D_001425C0[0].index].type;
   if (type==2 || type==3) colour=0x7F1010AF;
  }
  func_L01_004CAB30(v,v);
  life=func_00382498(8,17);
  particle=func_L01_00465738(m+0x10,v,colour,0xFF,life,0,-1,-1,0,94500.0f);
  if (particle) {
   *(f32 *)(particle+0x2C)=0.002400000113993883f;
   particle[2]=D_L01_0022116C[0][0];
  }
 }
}
