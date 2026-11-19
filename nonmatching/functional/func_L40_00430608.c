/* functional: high. NTSC draft with every PAL address, callee, global and the stat threshold (151 not 181) re-read against PAL asm; encoded-byte decode (step 5, xor with key address) agrees; compiles, 117 diff of scheduling */
/* localdecomp:start func_L40_00430608 */
extern u8 D_L40_003BFE20[];
extern u8 *D_L40_00249330[];
extern int D_001A5DF8[];
extern float D_001DC2C0_sda;
extern void func_L40_00430090(void *,int),func_L40_00430100(void *,int,int);
extern int func_L40_004300D8(void *),func_L40_00430068(void *),func_L40_004305B0(void *);
extern float func_L01_0040E548(void *,void *);
static __inline__ int decode42(u8 *key) {
 union { u8 bytes[8]; u32 words[2]; } value;
 u8 *out; int step,index,base;
 if(!*key)return 0;
 out=value.bytes;step=0;index=*key+1;base=((int)key-*key)&7;
 do { *out++=D_L40_003BFE20[index+((base+step)&7)*255];step+=5; }while(step<40);
 value.words[0]^=(u32)key;value.words[1]^=value.words[0];
 return value.words[1];
}
int func_L40_00430608(u8 *o,int mode) {
 u8 *p=*(u8 **)(o+0x68),*hero,*vehicle,*rider;
 int x,ok;u8 ignore;float range;
 if(!mode) {
  if(o[0x20]!=1)return 0;
  if(func_L40_004300D8(o))return 0;
  if(func_L40_00430068(o))return 0;
  if(*(int *)(p+0x1c)+1500 < D_001A5DF8[0]) {
   ok=1;
   if(*(int *)(p+0x1c)+40000 < D_001A5DF8[0] && !func_L40_004305B0(o)) {
    func_L40_00430100(o,0,255);ok=0;
   }
   if(ok)for(x=0;x<8;x++) {
    hero=D_L40_00249330[x];
    if(!hero)continue;
    if((decode42(hero+0x19e6)^20)==0)continue;
    if(*(int *)(hero+0x350)<151)continue;
    if(*(int *)(hero+0x2528))continue;
    vehicle=*(u8 **)(hero+0x2530);ignore=0;
    if(vehicle && vehicle[0x27b] && (decode42(hero+0x19e4)^49)==0)ignore=1;
    if(ignore)continue;
    rider=*(u8 **)(hero+0x2cc);range=D_001DC2C0_sda;
    if(rider && *(s16 *)(rider+0xaa)==0x10c3)continue;
    if(func_L01_0040E548(o+0x10,hero+0xa0)<range*range) {
     if(*(int *)(hero+0x2548)!=*(s16 *)(p+0x14)) {func_L40_00430090(o,x);return 0;}
     if(0.1f<func_L01_0040E548(p,o+0x10)){func_L40_00430100(o,0,hero[0x2544]);return 0;}
    }
   }
  }
 }
 return 0;
}
/* localdecomp:end func_L40_00430608 */
