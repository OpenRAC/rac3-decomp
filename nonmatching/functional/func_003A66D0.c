/* functional: high. Codex PAL near miss, re-verified line by line against the assembly: every constant (bit patterns), call, argument and packet offset agrees. Calls func_003A6578 through its matched prototype (start, step, count, a, b, scale, color), which puts the same values in the same registers as retail; func_0038DFB8 is declared (as func_0038DFB8_003A66D0, the repo's per-caller name) returning s32 (retail uses its v0; another unit declares it void). */
/* localdecomp:start func_003A66D0 */
typedef int Quad_003A66D0 __attribute__((mode(TI)));
typedef struct Packet_003A66D0 {
 f32 pos[4]; f32 vel[4]; f32 f20,f24,f28;
 s32 color0,color1,time0,time1,flags,time2,time3; u8 pad48[4]; s32 kind;
} Packet_003A66D0;
extern f32 D_001D6FA0[][4]; /* $gp-0x5910 */
__asm__(".extern D_001D6FA0, 4");
extern Quad_003A66D0 D_001DA010[];
extern s32 D_00225734[];
/* PAL, checked against the assembly: f = p[0x95]/128 * row.w; nine linear terms; two streaks via func_003A6578, then one spark packet to func_003A8668 */
void func_003A66D0(u8 *p, s32 n, s32 special)
{
 extern void func_003C3278(void *,s32,void *);
 extern void func_0038D408(void *,void *,void *);
 extern s32 func_0038DFB8_003A66D0(s32,s32,f32);
 extern void func_0038D200(f32 *,void *,f32);
 extern void func_003A6578(V4_3A0D58 *, V4_3A0D58 *, s32, f32, f32, f32, s32);
 extern void func_003A8708(void *,s32);
 extern f32 func_003828C0(f32,f32);
 extern s32 func_00382878(s32,s32);
 extern void func_003A8668(void *,void *);
 f32 pos[4] __attribute__((aligned(16)));
 f32 off[4] __attribute__((aligned(16)));
 f32 mat[16] __attribute__((aligned(16)));
 Packet_003A66D0 packet __attribute__((aligned(16)));
 f32 f, a,b,c,d,e,g,h,j,k;
 s32 color0,color1,time0,time1;
 f32 *row;
 func_003C3278(p,0,mat);
 row=D_001D6FA0[n];
 func_0038D408(pos,row,mat);
 f=p[0x95]*0.0078125f*row[3];
 a=f*0.05999999865889549f+0.05999999865889549f;
 b=f*0.0f+0.07499999552965164f;
 c=f*0.024999991059303284f+0.17499999701976776f;
 d=f*0.03999999910593033f+0.03999999910593033f;
 e=f*0.375f+0.375f;
 g=f*0.09999999403953552f+0.09999999403953552f;
 h=f*0.02499999850988388f+0.02499999850988388f;
 j=f*0.07499999552965164f+0.07499999552965164f;
 time0=(s32)(f*5.0f+15.0f);
 time1=(s32)(f*5.0f+25.0f);
 color0=func_0038DFB8_003A66D0(0x40204080,0x40205080,f);
 color1=func_0038DFB8_003A66D0(-1,-1,f);
 if (!special && (s8)p[0x95]>=0) {
  color0=(color0&0xFFFFFF)|((((color0>>24)*p[0x95])>>7)<<24);
  color1=(color1&0xFFFFFF)|((((color1>>24)*p[0x95])>>7)<<24);
 }
 func_0038D200(off,mat,-a);
 func_003A6578((V4_3A0D58 *)pos,(V4_3A0D58 *)off,time0,e,g,j,color0);
 if (!n) {
  func_0038D200(off,mat,-d);
  func_003A6578((V4_3A0D58 *)pos,(V4_3A0D58 *)off,time1,c,h,b,color1);
 }
 func_003A8708(p,0x3F3F3F);
 packet.color1=packet.color0=func_0038DFB8_003A66D0(0x2F7F,0x7F7F,func_003828C0(0.0f,1.0f));
 *(Quad_003A66D0 *)packet.pos=*(Quad_003A66D0 *)pos;
 packet.pos[0]+=func_003828C0(-0.025f,0.025f);
 packet.pos[1]+=func_003828C0(-0.025f,0.025f);
 packet.pos[2]+=func_003828C0(-0.025f,0.025f);
 *(Quad_003A66D0 *)packet.vel=D_001DA010[0];
 packet.f24=func_00382918();
 packet.f20=func_003828C0(90.0f,180.0f)*0.017453292f*0.020000001f;
 packet.kind=5;
 packet.flags=1;
 if (special) {
  packet.time1=packet.time0=func_00382878(40,56);
  packet.time3=packet.time2=(func_00382878(50,60)*5+2)/6;
  packet.f28=func_003828C0(0.8f,1.5f);
  if (p[0x95]>64) func_003A8668(p,&packet);
 } else {
  packet.time1=packet.time0=func_00382878(31,63);
  packet.time3=packet.time2=(func_00382878(70,90)*5+2)/6;
  packet.f28=func_003828C0(1.0f,2.0f);
  packet.flags|=((D_00225734[0]&1)+1)*2;
  func_003A8668(p,&packet);
 }
}
/* localdecomp:end func_003A66D0 */
