/* Unlinked NTSC-U draft. 3 differing words with inherited flags. The named image-buffer extern emits an extra low half and changes two call delay slots. */
/* NTSC-U native near miss: stock inherited @ps2as flags, 3 differing words.
 * Retail materializes the disc image buffer in a single lui. The required named
 * extern emits a low-half addiu and shifts two nearby call slots. Do not replace
 * the non-hardware address with a pointer literal or ordinary inline asm.
 */
#include "common.h"

/* localdecomp:start func_U_003982E0 */
typedef struct { s32 state; u8 pad4[0xA9]; u8 mode; u8 padAE[9]; u8 language; } State_003983C8;
typedef struct { u8 pad0[0x64C]; s32 base; u8 pad650[8]; s32 offset; s32 sectors; } Disc_003983C8;
typedef struct { u8 pad[0x78]; s32 heap; } Heap_003983C8;
typedef struct { u8 pad[0x24]; s32 a,b,c,d,e,f,g,h; } Sizes_003983C8;
typedef struct { u8 pad[0x18]; s32 a; u8 pad1C[0x14]; s32 b; } Cache_003983C8;
extern State_003983C8 D_00143950;
extern Disc_003983C8 D_00160C40;
extern Heap_003983C8 D_U_00227600;
extern Sizes_003983C8 D_001A1ED0;
extern Cache_003983C8 D_0016C580;
extern u8 D_0010F1A0[];
extern u8 D_U_01FEBEF8[];
extern u8 D_U_01FF8000[];
extern s32 D_U_01000000[];
extern s32 D_001D4B64, D_001D4B60, D_001D4B90, D_001D4BA0;
extern u8 D_U_00227740[];
extern u8 D_U_00227480[];
extern u8 D_001D551D;
extern s32 D_001D5520;
extern u8 D_001D5F08[];
__asm__(".extern D_001D551D, 16");
__asm__(".extern D_001D5520, 16");
__asm__(".extern D_001D4B64, 16");
__asm__(".extern D_001D4B60, 16");
__asm__(".extern D_001D4B90, 16");
__asm__(".extern D_001D4BA0, 16");
void func_U_003982E0(void)
{
    extern void func_0012A950(void);
    extern s32 func_0012D678(s32);
    extern void func_U_00391648(void);
    extern void func_U_003A0518(void);
    extern void func_U_00387ED0(s32);
    extern void func_0013D208();
    extern void func_0012D4D8(void *);
    extern void func_U_003A92C0(void);
    extern void func_U_003981A0(void);
    extern void func_U_003A9378(void);
    extern void func_U_003A9CB0(void);
    extern void func_U_00388320(void);
    extern void func_0012B300(s32);
    extern void func_0012B800(s32);
    extern s32 func_00124308(void *);
    extern s32 func_001242B8(void);
    extern void func_00121FE8(s32);
    extern void func_00124920(void);
    extern void func_00123B10(void);
    extern void func_00124970(void);
    extern s32 func_00123EA0(void);
    extern void func_U_003982C0(void);
    extern s32 func_001233F8(void);
    extern s32 func_0013D290(s32, s32, void *);
    extern void func_0011F0A0(s32);
    extern void func_U_0039C340(void *);
    extern void func_U_003A9200(u32);
    extern void func_0013D2E0(void *);
    extern void func_U_003A0A20(u8 *, u32);
    extern s32 func_00123B98(s32, s32, s32);
    extern s32 func_U_003980F0(s32, s32, s32, s32, s32);
    extern void func_U_003A87B8(void);
    extern void func_U_003A2E80(void);
    extern void func_U_0039E950(void);
    extern void func_U_00387620(void);
    extern void func_U_00387778();
    extern void func_U_003A4390(void);
    extern void func_U_003980C8(void);
    extern void func_U_003A1590(void);
    extern void func_U_0039A9A8(void);
    extern s32 func_0013A880(void);
    extern s32 func_0013A8E8(void);
    extern void func_U_0038CEA0(void *, s32, s32);
    extern void func_0012C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
    extern void func_0012CCC8(void *, void *);
    extern s32 func_0012A9F0(s32, s32);
    extern void func_U_003826C8(void);
    extern s32 func_U_00398738(s32);
    extern void func_U_00392D58(void *);
    u32 work[512];
    u32 sentinel;
    u8 *image;
    u8 *heap;
    s32 result;
    s32 savedHeap;
    func_0012A950();
    func_0012D678(1);
    if (!D_001D551D) { D_001D5520=0; D_00143950.mode=0; }
    func_U_00391648();
    func_U_003A0518();
    func_U_00387ED0(1);
    func_0012D4D8(func_0013D208);
    func_U_003A92C0(); func_U_003981A0(); func_U_003A92C0();
    func_U_003A9378(); func_U_003A9CB0(); func_U_00388320();
    func_0012B300(0); func_0012B800(0);
    while (!func_00124308(D_001D5F08)) {}
    while (!func_001242B8()) {}
    func_00121FE8(0); func_00124920(); image=(u8 *)D_U_01000000; func_00123B10(); func_00124970();
    func_00123EA0(); func_0012B300(0); func_0012B800(0); func_U_003982C0(); func_001233F8();
    func_0013D290(1000, 1, &work);
    func_0011F0A0(0);
    D_00143950.state=0;
    func_U_0039C340(&work);
    func_U_003A9200((u32)D_0010F1A0);
    func_0013D2E0(D_U_01FEBEF8);
    heap=D_U_01FF8000-(D_00160C40.sectors<<11);
    func_0013D290(D_00160C40.offset+D_00160C40.base, D_00160C40.sectors, heap);
    func_0011F0A0(0);
    func_U_003A0A20(heap, 0x1000000);
    result=func_00123B98(0,0x78000,0);
    sentinel=0x8012FC00;
    func_U_003980F0(*(s32 *)(image+0x40)+(s32)image,*(s32 *)(image+0x44),result,0x51,(s32)&sentinel-1);
    func_U_003A87B8(); func_0012B800(0); func_U_003A2E80();
    savedHeap=D_U_00227600.heap;
    D_001A1ED0.a=0;
    D_001A1ED0.b=0x60000; D_001A1ED0.c=0x70000; D_001A1ED0.d=0xB0000;
    D_001A1ED0.e=0xF0000; D_001A1ED0.f=0x160000; D_001A1ED0.g=0x1D0000; D_001A1ED0.h=0x1E0000;
    D_001D4B64=savedHeap;
    D_001D4B60=-1; D_001D4B90=-1; D_001D4BA0=-1;
    D_0016C580.b=-1; D_0016C580.a=-1;
    func_0012B800(0); func_U_0039E950(); func_U_00387620(); func_U_00387778(); func_U_003A9378();
    func_U_003980C8(); func_0012B800(0); func_U_003A4390(); func_U_003980C8();
    func_U_003A1590(); func_U_003980C8(); func_U_0039A9A8();
    if (!D_001D551D) {
        switch(func_0013A880()) {
        case 2: D_00143950.language=2;break;
        case 3: D_00143950.language=4;break;
                case 1: default: D_00143950.language=0;break;
        }
    }
    if (!D_001D551D) {
        switch(func_0013A8E8()) {
        case 1: D_00143950.mode=1;break;
        case 0: case 2: D_00143950.mode=0;break;
        }
    }
    func_U_0038CEA0(D_U_00227740,0x80808080,0x100);
    func_0012C9A0(&work,0x3FFB,1,0,0,0,8,8);
    func_0011F0A0(0);
    func_0012CCC8(&work,D_U_00227740);
    func_0012A9F0(0,0); func_U_003826C8(); func_U_00398738(0);
    *(volatile u32 *)0x10000810 = 0x82;
    *(volatile u32 *)0x10000800 = 0;
    func_U_00392D58(D_U_00227480);
    func_U_003980C8();
}

/* localdecomp:end func_U_003982E0 */
