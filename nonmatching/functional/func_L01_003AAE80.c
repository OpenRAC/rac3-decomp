/* functional: medium. Offsets taken from draft; no per-offset re-verification */
extern u8 *D_L01_0021F6C0[];
extern f32 D_001DE3A8_sda,D_001DE3D4_sda;
extern s32 D_001DE43C_sda;
__asm__(".extern D_001DE3A8_sda, 4");
__asm__(".extern D_001DE3D4_sda, 4");
__asm__(".extern D_001DE43C_sda, 4");
void func_L01_003AAE80(u8 *m, u8 *s) {
 extern void func_L01_00477BC0(s32,s32);
 extern f32 func_0038CED8(void *);
 extern f32 func_0038D160(f32,f32);
 extern void func_0038D308(void *,void *);
 extern void func_L01_003AB448(u8 *,Vec4_003AB448,Vec4_003AB448);
 extern f32 func_003824E0(f32,f32);
 extern Tbl_003A5118 *func_L01_0043B548(s32,s32);
 extern void func_L01_003AADB8(u8 *,G_003AADB8 *);
 extern void func_L01_004450F0(S_3A9AC0m *,int,int);
 Vec4_003AB448 pos,rot;
 Tbl_003A5118 *table;
 s32 changed=0,i;
 if(*(s32 *)(s+0x50)==0 || abs_asm(*(s32 *)(s+0x50))==2) {
  s32 sentinel=-1;
  s32 *ids=(s32 *)(s+0xc70), *states=(s32 *)(s+0xc80);
  for(i=0;i<4;ids++,i++,states++) {
   if(*states!=sentinel) {
    func_L01_00477BC0(*ids,0);
    changed=1;
   }
  }
  func_L01_00477BC0(*(s32 *)(s+0xc50),0);
 }
 m[0x30]=255;
 if(*(s16 *)(m+0x32)<128) *(s16 *)(m+0x32)=128;
 if(*(s32 *)(s+0xc50)!=-1 && !changed) {
  u8 *rotation=m+0xf0;
  {
   u8 *target=D_L01_0021F6C0[*(s32 *)(s+0xc50)];
   __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
    : "=m"(pos) : "m"(*(Vec4_003AB448 *)(target+0x10)), "m"(*(Vec4_003AB448 *)(m+0x10)) : "vf1","vf2");
  }
  qzero(rotation);
  *(f32 *)(m+0xf4)=-func_0038D160(func_0038CED8(&pos),pos.v[2]);
  *(f32 *)(m+0xf8)=func_0038D160(pos.v[0],pos.v[1]);
  func_0038D308(m+0xc0,rotation);
 }
 pos=*(Vec4_003AB448 *)(m+0x10);
 rot=*(Vec4_003AB448 *)(m+0xf0);
 func_L01_003AB448(s,pos,rot);
 { f32 amplitude=D_001DE3A8_sda;
 *(s32 *)(s+0xd20)=0;
 *(s32 *)(s+0xd1c)=-1;
 *(s32 *)(s+0xd0c)=-1;
 *(f32 *)(s+0xd00)=func_003824E0(-amplitude,amplitude); }
 *(f32 *)(s+0xd04)=func_003824E0(0.0f,3.141592741f);
 { f32 phase=func_003824E0(0.0f,3.141592741f);
 f32 speed=D_001DE3D4_sda*0.020000001415610313f;
 f32 scale;
 qzero(s+0xd50);
 scale=*(f32 *)(s+0xc64);
 *(f32 *)(s+0xd08)=phase;
 *(f32 *)(s+0xd18)=speed*scale;
 *(f32 *)(s+0xc44)=1.0f;
 *(f32 *)(s+0xc6c)=*(f32 *)(s+0xc64);
 *(s32 *)(s+0xc40)=0;
 *(f32 *)(s+0xcfc)=0.0f;
 *(s32 *)(s+0xc60)=0;
 *(s32 *)(s+0xcec)=-1;
 *(s32 *)(s+0x64)=0;
 *(s32 *)(s+0x68)=0;
 *(s32 *)(s+0xc48)=0; }
 if(*(s32 *)(s+0x50)>0) {
  s32 i;
  table=func_L01_0043B548(6625,108);
  *(s32 *)(s+0x50)=-*(s32 *)(s+0x50);
  for(i=0;i<4;i++) {
   if(((s32 *)(s+0xc80))[i]!=-1) break;
  }
  if(i<4) {
   u8 *target=D_L01_0021F6C0[*(s32 *)(s+(i<<2)+0xc70)];
   *(u128_t *)(s+0xd30)=*(u128_t *)(target+0x10);
   __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
    : "=m"(pos) : "m"(*(Vec4_003AB448 *)(target+0x20)), "m"(*(Vec4_003AB448 *)(target+0x10)) : "vf1","vf2");
   qzero(s+0xd40);
   *(f32 *)(s+0xd44)=-func_0038D160(func_0038CED8(&pos),pos.v[2]);
   *(f32 *)(s+0xd48)=func_0038D160(pos.v[0],pos.v[1]);
  } else {
   *(u128_t *)(s+0xd30)=*(u128_t *)(m+0x10);
   *(u128_t *)(s+0xd40)=*(u128_t *)(m+0xf0);
  }
  s[0x5e]=6;
  s[0x5f]=4;
  table->f0(m);
 } else if(*(s16 *)(s+0xd2e)) {
  func_L01_003AADB8(m,(G_003AADB8 *)s);
  *(s32 *)(s+0xcf4)=D_001DE43C_sda;
  *(f32 *)(s+0xc44)=0.0f;
  func_L01_004450F0((S_3A9AC0m *)m,2,1);
 } else {
  func_L01_004450F0((S_3A9AC0m *)m,1,0);
 }
}
