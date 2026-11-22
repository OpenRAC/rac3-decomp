/* func_00397FE8 (frontbin), boot_elf func_003983C8's draft with its names moved (config/frontend_pairs.tsv).
   Near miss (FE-1, 2026-11-21): 2 differences. The EE hardware registers are written at their literal
   addresses now (*(volatile u32 *)0x10000810 = 0x82 and 0x10000800 = 0, allowed by AGENTS.md), where the draft
   had section(".data") volatile declarations; that took it from 21 differences to 2. Left: retail builds the
   image address 0x01000000 with a single `lui $s1, 0x100`; the named D_01000000 gives lui plus `addiu $s1, $s1, 0`
   (the %lo) and moves an addiu into a jal delay slot. The literal `(u8 *)0x01000000` (not hardware memory,
   so not allowed) gives the lui alone but 7 differences in the load order of image+0x40 and +0x44.
   With --no-context; in src/frontbin/397D48.c its prototype of func_00392A38 conflicts with the file's. */

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
void func_00397FE8(void)
{
    extern void func_0012A950(void);
    extern s32 func_0012D678(s32);
    extern void func_00391328(void);
    extern void func_003A0258(void);
    extern void func_00387B18(s32);
    extern void func_0013D208();
    extern void func_0012D4D8(void *);
    extern void func_003A9050(void);
    extern void func_00397EA8(void);
    extern void func_003A9108(void);
    extern void func_003A9A40(void);
    extern void func_00387F68(void);
    extern void func_0012B300(s32);
    extern void func_0012B800(s32);
    extern s32 func_00124308(void *);
    extern s32 func_001242B8(void);
    extern void func_00121FE8(s32);
    extern void func_00124920(void);
    extern void func_00123B10(void);
    extern void func_00124970(void);
    extern s32 func_00123EA0(void);
    extern void func_00397FC8(void);
    extern s32 func_001233F8(void);
    extern s32 func_0013D290(s32, s32, void *);
    extern void func_0011F0A0(s32);
    extern void func_0039C078(void *);
    extern void func_003A8F90(u32);
    extern void func_0013D2E0(void *);
    extern void func_003A0760(u8 *, u32);
    extern s32 func_00123B98(s32, s32, s32);
    extern s32 func_00397DF8(s32, s32, s32, s32, s32);
    extern void func_003A8500(void);
    extern void func_003A2BC0(void);
    extern void func_0039E688(void);
    extern void func_00387268(void);
    extern void func_003873C0();
    extern void func_003A40D0(void);
    extern void func_00397DD0(void);
    extern void func_003A12D0(void);
    extern void func_0039A6E0(void);
    extern s32 func_0013A880(void);
    extern s32 func_0013A8E8(void);
    extern void func_0038CB78(void *, s32, s32);
    extern void func_0012C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
    extern void func_0012CCC8(void *, void *);
    extern s32 func_0012A9F0(s32, s32);
    extern void func_003822C8(void);
    extern s32 func_00398470(s32);
    extern void func_00392A38(void *);
    u32 work[512];
    u32 sentinel;
    u8 *image;
    u8 *heap;
    s32 result;
    s32 savedHeap;
    func_0012A950();
    func_0012D678(1);
    if (!D_001D551D) { D_001D5520=0; D_00143950.mode=0; }
    func_00391328();
    func_003A0258();
    func_00387B18(1);
    func_0012D4D8(func_0013D208);
    func_003A9050(); func_00397EA8(); func_003A9050();
    func_003A9108(); func_003A9A40(); func_00387F68();
    func_0012B300(0); func_0012B800(0);
    while (!func_00124308(D_001D5F08)) {}
    while (!func_001242B8()) {}
    func_00121FE8(0); func_00124920(); image=(u8 *)D_01000000; func_00123B10(); func_00124970();
    func_00123EA0(); func_0012B300(0); func_0012B800(0); func_00397FC8(); func_001233F8();
    func_0013D290(1000, 1, &work);
    func_0011F0A0(0);
    D_00143950.state=1;
    func_0039C078(&work);
    func_003A8F90((u32)D_0010F1A0);
    func_0013D2E0(D_01FEBEF8);
    heap=D_01FF8000-(D_00160C40.sectors<<11);
    func_0013D290(D_00160C40.offset+D_00160C40.base, D_00160C40.sectors, heap);
    func_0011F0A0(0);
    func_003A0760(heap, 0x1000000);
    result=func_00123B98(0,0x78000,0);
    sentinel=0x8012FC00;
    func_00397DF8(*(s32 *)(image+0x40)+(s32)image,*(s32 *)(image+0x44),result,0x51,(s32)&sentinel-1);
    func_003A8500(); func_0012B800(0); func_003A2BC0();
    savedHeap=D_00227580.heap;
    D_001A1ED0.a=0;
    D_001A1ED0.b=0x60000; D_001A1ED0.c=0x70000; D_001A1ED0.d=0xB0000;
    D_001A1ED0.e=0xF0000; D_001A1ED0.f=0x160000; D_001A1ED0.g=0x1D0000; D_001A1ED0.h=0x1E0000;
    D_001D4B64=savedHeap;
    D_001D4B60=-1; D_001D4B90=-1; D_001D4BA0=-1;
    D_0016C580.b=-1; D_0016C580.a=-1;
    func_0012B800(0); func_0039E688(); func_00387268(); func_003873C0(); func_003A9108();
    func_00397DD0(); func_0012B800(0); func_003A40D0(); func_00397DD0();
    func_003A12D0(); func_00397DD0(); func_0039A6E0();
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
    func_0038CB78(D_002276C0,0x80808080,0x100);
    func_0012C9A0(&work,0x3FFB,1,0,0,0,8,8);
    func_0011F0A0(0);
    func_0012CCC8(&work,D_002276C0);
    func_0012A9F0(0,0); func_003822C8(); func_00398470(0);
    *(volatile u32 *)0x10000810 = 0x82;
    *(volatile u32 *)0x10000800 = 0;
    func_00392A38(D_00227400);
    func_00397DD0();
}

