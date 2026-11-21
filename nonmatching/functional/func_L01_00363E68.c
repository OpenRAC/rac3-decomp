/* functional: high. 66 words differ (VU0 scheduling, loop order); stack layout, packet tags (0x4A, 0x54), uv table, prim words verified against asm; draft kept with inline lqc2 asm */
/* localdecomp:start func_L01_00363E68 */
typedef int Q_00363E68 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00363E68;
extern Q_00363E68 D_L01_001E2A40[];
extern Q_00363E68 D_001A4EC0[];
extern Q_00363E68 D_L01_001D7C50[];
static __inline__ void sub_00363E68(Q_00363E68 *d, Q_00363E68 *a, Q_00363E68 *b) {
 __asm__("lqc2 $vf1,%2\n\tlqc2 $vf2,%1\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(*d) : "m"(*a),"m"(*b) : "vf1","vf2");
}
static __inline__ void add_00363E68(Q_00363E68 *d, Q_00363E68 *a, Q_00363E68 *b) {
 __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*d) : "m"(*a),"m"(*b) : "vf1","vf2");
}
void func_L01_00363E68(Q_00363E68 *point,s32 texture,f32 scale,f32 offset,f32 angle,f32 size) {
 extern void func_003D93B0(void *,s32,s32,s32);
 extern void func_0038CF68(void *,void *,f32);
 extern void func_0038CE90(void *,void *,void *);
 extern void func_0038D308(void *,void *);
 extern void func_0038D5F0(void *,void *,void *);
 extern void func_0038CE20(Q_00363E68 *,Q_00363E68 *,f32);
 extern void func_0038D028(void *,void *,void *);
 extern void func_003A9440(long,long);
 extern void func_003D2DA0(void *,s32,s32);
 extern void func_00389478(void *,void *,void *);
 struct { Q_00363E68 xyz[4]; u32 color[4]; f32 uv[8]; u8 pad[0x18]; unsigned long prim; } packet;
 struct { Q_00363E68 basis[3]; Q_00363E68 pos; V_00363E68 tmp; Q_00363E68 rotation[3]; } local;
 s32 i,j,k;
 func_003D93B0(&packet,texture,1,128);
 local.pos=*point;
 packet.prim=0x800000004AUL;
 packet.color[0]=0x80808080;
 packet.color[3]=0x80808080;
 packet.color[2]=0x80808080;
 packet.color[1]=0x80808080;
 packet.uv[0]=0;
 packet.uv[1]=0;
 packet.uv[2]=0;
 packet.uv[3]=1;
 packet.uv[4]=1;
 packet.uv[5]=0;
 packet.uv[6]=1;
 packet.uv[7]=1;
 __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(local.basis[0]) : "m"(D_L01_001E2A40[0]),"m"(local.pos) : "vf1","vf2");
 func_0038CF68(local.basis,local.basis,1.0f);
 func_0038CE90(local.basis+1,local.basis,D_001A4EC0);
 func_0038CF68(local.basis+1,local.basis+1,1.0f);
 func_0038CE90(local.basis+2,local.basis+1,local.basis);
 if(angle!=0.0f) {
  *(Q_00363E68 *)&local.tmp=0; local.tmp.x=angle;
  func_0038D308(local.rotation,&local.tmp);
  func_0038D5F0(local.basis,local.basis,local.rotation);
 }
 func_0038CE20((Q_00363E68 *)&local.tmp,local.basis,offset);
 add_00363E68(&local.pos,&local.pos,(Q_00363E68 *)&local.tmp);
 for(i=3;i>=0;i--) {
  func_0038CE20(packet.xyz+(3-i),D_L01_001D7C50+(3-i),scale);
  func_0038D028(packet.xyz+(3-i),packet.xyz+(3-i),local.basis);
 }
 func_003A9440(0x47,0x31001);
 func_003D2DA0(&packet,0,0);
 local.rotation[0]=packet.xyz[0];
 for(j=2;j>=0;j--) add_00363E68(local.rotation,local.rotation,packet.xyz+(3-j));
 func_0038CE20(local.rotation,local.rotation,0.25f);
 for(k=3;k>=0;k--) {
  sub_00363E68(local.rotation+1,packet.xyz+(3-k),local.rotation);
  func_0038CE20(local.rotation+1,local.rotation+1,size);
  add_00363E68(local.rotation+1,local.rotation,local.rotation+1);
  func_00389478(local.rotation+1,((u8 *)&packet)+0x50+(3-k)*8,((u8 *)&packet)+0x54+(3-k)*8);
 }
 func_003D93B0(&packet,-1,1,128);
 packet.prim=0x2000000054UL;
 func_003A9440(0x47,0x53001);
 func_003D2DA0(&packet,0,0);
 func_003A9440(0x47,0x5360B);
}
/* localdecomp:end func_L01_00363E68 */
