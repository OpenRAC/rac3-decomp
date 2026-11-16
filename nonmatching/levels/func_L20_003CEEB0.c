/* PAL near miss (Codex wave 6): near miss: 8 words differ with the file's flags.
 * Worker's note: 8 instruction differences, size unchanged: build/codex/w276/func_L20_003CEEB0.baseline.log. Inline update helper and pointer-to-array wording reproduce identical wrong bytes; pointer to indices is a3 rather than a1, missing a1-to-a3 copy at both copy ...
 */
#include "common.h"
/* localdecomp:start func_L20_003CEEB0 */
#include "vu0.h"
extern s32 D_L20_001DEB78;
extern s32 D_L20_001DEB7C;
extern s32 D_L20_001DEB20;
extern s32 D_L20_001DEB1C;
extern s32 D_L20_001DEB24;
__asm__(".extern D_L20_001DEB78, 4");
__asm__(".extern D_L20_001DEB7C, 4");
__asm__(".extern D_L20_001DEB20, 4");
__asm__(".extern D_L20_001DEB1C, 4");
__asm__(".extern D_L20_001DEB24, 4");
static __inline__ void add_003CEEB0(void *d,void *other) {
    vu0_q a,b;
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(vu0_v4 *)d));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(vu0_v4 *)other));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(a) : "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(a));
}
static __inline__ void copy_one_003CEEB0(void *d,void *a) { *(vu0_q *)d=*(vu0_q *)a; }
void func_L20_003CEEB0(u8 *obj) {
    extern s32 func_0038DBD8(s32,s32,f32);
    u8 *s=*(u8 **)(obj+0x68);


    if (*(s16 *)(s+0x22)) {
        u8 *indices=s+0x28;
        (*(s16 *)(s+0x22))--;
        { s32 n; u8 *p=s+0x70; for (n=22;n>=0;n--,p+=16) add_003CEEB0(p,p+0x200); }
        { s32 i,j; for (i=0;i<4.0f;) {
            s32 next=i+1;
            vu0_v4 *p=(vu0_v4 *)((i<<4)+(s32)s+0x470);
            for (j=2;j>=0;j--,p+=4) add_003CEEB0(p,p+16);
            i=next;
        }}
        { s32 k; for (k=0;k<4;k++) copy_one_003CEEB0(k*16+s+0x430,s+indices[k]*16+0x30); }
    }
    if (*(s16 *)(s+0x22)>D_L20_001DEB78) {
        *(s32 *)(s+0x24)=func_0038DBD8(D_L20_001DEB20,D_L20_001DEB1C,(f32)(*(s16 *)(s+0x22)-D_L20_001DEB78)/(f32)(*(s32 *)(s+8)-D_L20_001DEB78));
    } else if (*(s16 *)(s+0x22)>D_L20_001DEB7C) {
        *(s32 *)(s+0x24)=func_0038DBD8(D_L20_001DEB24,D_L20_001DEB20,(f32)(*(s16 *)(s+0x22)-D_L20_001DEB7C)/(f32)(D_L20_001DEB78-D_L20_001DEB7C));
    } else *(s32 *)(s+0x24)=0;
    if (*(s16 *)(s+0x22)) {
        u8 *indices=s+0x28;
        (*(s16 *)(s+0x22))--;
        { s32 n; u8 *p=s+0x680; for (n=22;n>=0;n--,p+=16) add_003CEEB0(p,p+0x200); }
        { s32 i,j; for (i=0;i<4.0f;) {
            s32 next=i+1;
            vu0_v4 *p=(vu0_v4 *)((i<<4)+(s32)s+0xa80);
            for (j=2;j>=0;j--,p+=4) add_003CEEB0(p,p+16);
            i=next;
        }}
        { s32 k; for (k=0;k<4;k++) copy_one_003CEEB0(k*16+s+0xa40,s+indices[k]*16+0x640); }
    }
}
/* localdecomp:end func_L20_003CEEB0 */
