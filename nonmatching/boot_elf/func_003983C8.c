/* func_003983C8 (boot_elf), the Codex wave 10 PAL near miss (20 words differed), revised.
   Near miss (FE-1, 2026-11-21): 2 differences. The EE hardware registers are written at their literal
   addresses now (*(volatile u32 *)0x10000810 = 0x82 and 0x10000800 = 0, allowed by AGENTS.md), where the draft
   had section(".data") volatile declarations; that took it from 21 differences to 2. Left: retail builds the
   image address 0x01000000 with a single `lui $s1, 0x100`; the named D_01000000 gives lui plus `addiu $s1, $s1, 0`
   (the %lo) and moves an addiu into a jal delay slot. The literal `(u8 *)0x01000000` (not hardware memory,
   so not allowed) gives the lui alone but 7 differences in the load order of image+0x40 and +0x44. */

typedef struct { s32 state; u8 pad4[0xA9]; u8 mode; u8 padAE[9]; u8 language; } State_003983C8;
typedef struct { u8 pad0[0x64C]; s32 base; u8 pad650[8]; s32 offset; s32 sectors; } Disc_003983C8;
typedef struct { u8 pad[0x78]; s32 heap; } Heap_003983C8;
typedef struct { u8 pad[0x24]; s32 a,b,c,d,e,f,g,h; } Sizes_003983C8;
typedef struct { u8 pad[0x18]; s32 a; u8 pad1C[0x14]; s32 b; } Cache_003983C8;
extern State_003983C8 D_00143950;
extern Disc_003983C8 D_00160C40;
extern Heap_003983C8 D_00227580;
extern Sizes_003983C8 D_001A1ED0;
extern Cache_003983C8 D_0016C580;
extern u8 D_0010F1A0[];
extern u8 D_01FEBEF8[];
extern u8 D_01FF8000[];
extern s32 D_01000000[];
extern s32 D_001D4B64, D_001D4B60, D_001D4B90, D_001D4BA0;
extern u8 D_002276C0[];
extern u8 D_00227400[];
extern u8 D_001D551D;
extern s32 D_001D5520;
extern u8 D_001D5F08[];
__asm__(".extern D_001D551D, 16");
__asm__(".extern D_001D5520, 16");
__asm__(".extern D_001D4B64, 16");
__asm__(".extern D_001D4B60, 16");
__asm__(".extern D_001D4B90, 16");
__asm__(".extern D_001D4BA0, 16");
void func_003983C8(void)
{
    extern void func_0012A950(void);
    extern s32 func_0012D678(s32);
    extern void func_00391708(void);
    extern void func_003A0658(void);
    extern void func_00387EF8(s32);
    extern void func_0013D208();
    extern void func_0012D4D8(void *);
    extern void func_003A9408(void);
    extern void func_00398288(void);
    extern void func_003A94C0(void);
    extern void func_003A9DF8(void);
    extern void func_00388348(void);
    extern void func_0012B300(s32);
    extern void func_0012B800(s32);
    extern s32 func_00124308(void *);
    extern s32 func_001242B8(void);
    extern void func_00121FE8(s32);
    extern void func_00124920(void);
    extern void func_00123B10(void);
    extern void func_00124970(void);
    extern s32 func_00123EA0(void);
    extern void func_003983A8(void);
    extern s32 func_001233F8(void);
    extern s32 func_0013D290(s32, s32, void *);
    extern void func_0011F0A0(s32);
    extern void func_0039C458(void *);
    extern void func_003A9348(u32);
    extern void func_0013D2E0(void *);
    extern void func_003A0B60(u8 *, u32);
    extern s32 func_00123B98(s32, s32, s32);
    extern s32 func_003981D8(s32, s32, s32, s32, s32);
    extern void func_003A8900(void);
    extern void func_003A2FC0(void);
    extern void func_0039EA68(void);
    extern void func_00387648(void);
    extern void func_003877A0();
    extern void func_003A44D0(void);
    extern void func_003981B0(void);
    extern void func_003A16D0(void);
    extern void func_0039AAC0(void);
    extern s32 func_0013A880(void);
    extern s32 func_0013A8E8(void);
    extern void func_0038CF58(void *, s32, s32);
    extern void func_0012C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
    extern void func_0012CCC8(void *, void *);
    extern s32 func_0012A9F0(s32, s32);
    extern void func_003826A8(void);
    extern s32 func_00398850(s32);
    extern void func_00392E18(void *);
    u32 work[512];
    u32 sentinel;
    u8 *image;
    u8 *heap;
    s32 result;
    s32 savedHeap;
    func_0012A950();
    func_0012D678(1);
    if (!D_001D551D) { D_001D5520=0; D_00143950.mode=0; }
    func_00391708();
    func_003A0658();
    func_00387EF8(1);
    func_0012D4D8(func_0013D208);
    func_003A9408(); func_00398288(); func_003A9408();
    func_003A94C0(); func_003A9DF8(); func_00388348();
    func_0012B300(0); func_0012B800(0);
    while (!func_00124308(D_001D5F08)) {}
    while (!func_001242B8()) {}
    func_00121FE8(0); func_00124920(); image=(u8 *)D_01000000; func_00123B10(); func_00124970();
    func_00123EA0(); func_0012B300(0); func_0012B800(0); func_003983A8(); func_001233F8();
    func_0013D290(1000, 1, &work);
    func_0011F0A0(0);
    D_00143950.state=1;
    func_0039C458(&work);
    func_003A9348((u32)D_0010F1A0);
    func_0013D2E0(D_01FEBEF8);
    heap=D_01FF8000-(D_00160C40.sectors<<11);
    func_0013D290(D_00160C40.offset+D_00160C40.base, D_00160C40.sectors, heap);
    func_0011F0A0(0);
    func_003A0B60(heap, 0x1000000);
    result=func_00123B98(0,0x78000,0);
    sentinel=0x8012FC00;
    func_003981D8(*(s32 *)(image+0x40)+(s32)image,*(s32 *)(image+0x44),result,0x51,(s32)&sentinel-1);
    func_003A8900(); func_0012B800(0); func_003A2FC0();
    savedHeap=D_00227580.heap;
    D_001A1ED0.a=0;
    D_001A1ED0.b=0x60000; D_001A1ED0.c=0x70000; D_001A1ED0.d=0xB0000;
    D_001A1ED0.e=0xF0000; D_001A1ED0.f=0x160000; D_001A1ED0.g=0x1D0000; D_001A1ED0.h=0x1E0000;
    D_001D4B64=savedHeap;
    D_001D4B60=-1; D_001D4B90=-1; D_001D4BA0=-1;
    D_0016C580.b=-1; D_0016C580.a=-1;
    func_0012B800(0); func_0039EA68(); func_00387648(); func_003877A0(); func_003A94C0();
    func_003981B0(); func_0012B800(0); func_003A44D0(); func_003981B0();
    func_003A16D0(); func_003981B0(); func_0039AAC0();
    if (!D_001D551D) {
        switch(func_0013A880()) {
        case 2: D_00143950.language=2;break;
        case 3: D_00143950.language=4;break;
        case 4: D_00143950.language=3;break;
        case 5: D_00143950.language=5;break;
        case 1: default: D_00143950.language=0;break;
        }
    }
    if (!D_001D551D) {
        switch(func_0013A8E8()) {
        case 1: D_00143950.mode=1;break;
        case 0: case 2: D_00143950.mode=0;break;
        }
    }
    func_0038CF58(D_002276C0,0x80808080,0x100);
    func_0012C9A0(&work,0x3FFB,1,0,0,0,8,8);
    func_0011F0A0(0);
    func_0012CCC8(&work,D_002276C0);
    func_0012A9F0(0,0); func_003826A8(); func_00398850(0);
    *(volatile u32 *)0x10000810 = 0x82;
    *(volatile u32 *)0x10000800 = 0;
    func_00392E18(D_00227400);
    func_003981B0();
}

