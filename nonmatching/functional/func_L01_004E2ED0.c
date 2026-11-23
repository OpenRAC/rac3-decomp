/* functional: high. 2-word near miss (VU0 sqc2/move order); vsub/vadd as COP2 inline asm. D_001A4BE0 extern dropped (already in the file context). */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_004E2ED0;
typedef struct {
 u8 p0[0x1200]; u8 *parts[7][20];
 u8 p1430[0x22D0-0x1430]; f32 sx,sy,sz;
 u8 p22DC[0x25C0-0x22DC]; u8 *moby;
 u8 p25C4[0x25E4-0x25C4]; u8 mode;
 u8 p25E5[0x2888-0x25E5]; s16 active,index;
} H_004E2ED0;
extern f32 D_L01_002F4280[];
void func_L01_004E2ED0(void) {
 extern void func_0038D278(void *);
 extern void func_0038CF68(void *, void *, f32);
 extern void func_0038D5F0(void *, void *, void *);
 extern void func_0038D000(void *, void *, void *);
 V_004E2ED0 scale[3],matrix[3],pos;

 s32 i,j;
 if (!(*(H_004E2ED0 *)&D_001A4BE0).active) return;
 if ((*(H_004E2ED0 *)&D_001A4BE0).index) {
  f32 v=D_L01_002F4280[++(*(H_004E2ED0 *)&D_001A4BE0).index];
  if(v == -1.0f) { (*(H_004E2ED0 *)&D_001A4BE0).active=0;(*(H_004E2ED0 *)&D_001A4BE0).index=0;return; }
  (*(H_004E2ED0 *)&D_001A4BE0).sx=v;(*(H_004E2ED0 *)&D_001A4BE0).sz=1.0f;(*(H_004E2ED0 *)&D_001A4BE0).sy=v;
 }
 func_0038D278(scale);
 func_0038CF68(&scale[0],&scale[0],(*(H_004E2ED0 *)&D_001A4BE0).sx);
 func_0038CF68(&scale[1],&scale[1],(*(H_004E2ED0 *)&D_001A4BE0).sy);
 func_0038CF68(&scale[2],&scale[2],(*(H_004E2ED0 *)&D_001A4BE0).sz);
 func_0038D5F0(matrix,scale,(u8 *)&D_001A4BE0+0x40);
 func_0038D5F0(matrix,&D_001A4BE0,matrix);
 func_0038D5F0((*(H_004E2ED0 *)&D_001A4BE0).moby+0xC0,(*(H_004E2ED0 *)&D_001A4BE0).moby+0xC0,scale);
 if (!(*(H_004E2ED0 *)&D_001A4BE0).mode) {
  for(i=0;i<7;i++) {
   for(j=0;j<3;j++) {
    u8 *base=(u8 *)&D_001A4BE0 + i*80;
    u8 *p=*(u8 **)(base+0x1200);
    if(j==1)p=*(u8 **)(base+0x1204);else if(j==2)p=*(u8 **)(base+0x1208);
    if(p) {
     func_0038D5F0(p+0xC0,matrix,p+0xC0);
     __asm__ __volatile__("lqc2 vf2,%0\n\tlqc2 vf1,%1\n\tvsub.xyz vf2,vf2,vf1" : : "m"(*(V_004E2ED0 *)(p+0x10)), "m"(*(V_004E2ED0 *)((u8 *)&D_001A4BE0+0x80)) : "vf1","vf2");
     __asm__ __volatile__("sqc2 vf2,0(%1)" : "=m"(pos) : "r"(&pos) : "vf2");
     func_0038D000(&pos,&pos,matrix);
     __asm__("lqc2 vf1,%1\n\tlqc2 vf2,%2\n\tvadd.xyz vf1,vf1,vf2\n\tsqc2 vf1,%0" : "=m"(*(V_004E2ED0 *)(p+0x10)) : "m"(pos), "m"(*(V_004E2ED0 *)((u8 *)&D_001A4BE0+0x80)) : "vf1","vf2");
    }
   }
  }
 }
 if(!(*(H_004E2ED0 *)&D_001A4BE0).index && (*(H_004E2ED0 *)&D_001A4BE0).sx==1.0f && (*(H_004E2ED0 *)&D_001A4BE0).sy==1.0f && (*(H_004E2ED0 *)&D_001A4BE0).sz==1.0f) (*(H_004E2ED0 *)&D_001A4BE0).active=0;
 (*(H_004E2ED0 *)&D_001A4BE0).sx=1.0f;(*(H_004E2ED0 *)&D_001A4BE0).sy=1.0f;(*(H_004E2ED0 *)&D_001A4BE0).sz=1.0f;
}
