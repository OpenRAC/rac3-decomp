#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 133BB8.c's earlier functions (tools/port_from_us.py) */
extern s32 func_00124920(void);
extern void func_00124970_00133BB8(void);
typedef struct {
    u8 pad0[0x12C];
    int f12C;
    u8 pad130[0x13C - 0x130];
    int f13C;
    u8 pad140[0x1C0 - 0x140];
    int f1C0;
    int f1C4;
    u8 pad1C8[0x878 - 0x1C8];
    int f878;
} S_133C58;
void func_00134D68(void *s);
void func_00134D60(void *s);
int func_00132970(void *s, int n);
int func_00132888_00133C58(void *s, int n);
void func_00134C00_00133C58(void *s, int n);
int func_00132428(void *s);
void func_0013A150(void *s, char *fmt, int x);
extern s32 func_0013A0F8();
extern char D_00151DF8[];
extern char D_00151E20[];
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0x68 - 0x14];
} Fb_133DF8;
typedef struct {
    u8 pad0[0x10C];
    u32 f10C;
    u32 f110;
    u32 f114;
    s32 f118[3];
    s32 f124;
    u8 pad128[0x134 - 0x128];
    s32 f134;
    s32 f138;
    s32 f13C;
    s32 f140;
    u8 pad144[0x14C - 0x144];
    s32 f14C;
    s32 f150;
    s32 f154;
    u8 pad158[0x184 - 0x158];
    s32 f184;
    s32 f188;
    s32 f18C;
    u8 pad190[0x198 - 0x190];
    s32 f198;
    u8 pad19C[0x1F8 - 0x19C];
    Fb_133DF8 fb[9];
    u8 pad5A0[0x858 - 0x5A0];
    s32 f858;
    u8 pad85C[0x87C - 0x85C];
    s32 f87C;
} S_133DF8;
typedef struct {
    s32 w;
    s32 h;
    u8 pad8[0x40 - 8];
    S_133DF8 *q;
} H_133DF8;
extern void func_00136000();
extern u32 func_00136010();
typedef struct {
    u8 pad0[0x160];
    s32 f160;
    s32 f164;
    s32 f168;
    s32 f16C;
    s32 f170;
    u8 pad174[0x1BC - 0x174];
    s32 f1BC;
    u8 pad1C0[0x85C - 0x1C0];
    s32 f85C;
    s32 f860;
    s32 f864;
} S_134460;
extern u32 func_00132888();
extern void func_00134C00();
extern void func_001349F8();
typedef struct {
    u8 pad0[0x134];
    u32 f134;
    u32 f138;
    u8 pad13C[0x144 - 0x13C];
    int f144;
    int f148;
    int f14C;
    int f150;
    u8 pad154[0x858 - 0x154];
    int f858;
} S_1345A8;
extern char D_00151E60[];
extern char D_00151E88[];
int func_00132888_001345A8(void *s, int n);
extern s32 func_0013A0F8();
typedef struct {
    u8 pad0[0x828];
    s32 x828;           
    u32 x82C;           
    u8 pad830[0x850 - 0x830];
    u32 x850;           
    u32 x854;           
} S_1346E8;
extern u32 func_00132888();
extern void func_00134BC8(S_1346E8 *);
extern s32 func_0013A0F8();
extern char D_00151EA8[];
extern char D_00151ED0[];
typedef struct { u8 pad[0x878]; s32 x878; } S_1349F8;
typedef struct { void (*f[11])(S_1349F8 *); } T_1349F8;
extern void func_00134D68_001349F8(S_1349F8 *);
extern void func_00134D60_001349F8(S_1349F8 *);
extern void func_00134C00_001349F8(S_1349F8 *, s32);
extern s32 func_00132970_001349F8(S_1349F8 *, s32);
extern u32 func_00132888_001349F8(S_1349F8 *, s32);
extern u8 D_00151FB8[];
typedef struct {
    u8 pad0[0x160];
    s32 f160;
    u8 pad164[0x838 - 0x164];
    long f838;
    long f840;
    u8 pad848[0x868 - 0x848];
    s32 f868;
    u8 pad86C[0x878 - 0x86C];
    s32 f878;
} S_134C08;
typedef struct {
    s32 type;
    s32 pad4;
    long f8;
    long f10;
} Cb_134C08;
extern void func_00134D68_00134C08();
extern void func_00134C00();
extern s32 func_00132970_00134C08();
extern u32 func_00132888();
extern void func_00134110();
extern void func_001343C0();
extern void func_00134460();
extern s32 func_00135D50(s32, s32 *);
extern u32 func_00132888();
typedef struct {
    u8 pad[0x154];
    s32 f154;
    s32 f158;
    s32 f15C;
} S_134DB8;
typedef struct {
    u8 pad0[0x14C];
    s32 f14C;
    u8 pad150[0x184 - 0x150];
    s32 f184;
    s32 f188;
    u8 pad18C[0x194 - 0x18C];
    s32 f194;
    u8 pad198[0x19C - 0x198];
    s32 hoff[3];
    s32 voff[3];
} S_134EE0;
extern u32 func_00132888();
typedef struct {
    u8 pad0[0x68];
} Fb_1350A8;
typedef struct {
    Fb_1350A8 *a;
    Fb_1350A8 *b;
    s32 pad;
    Fb_1350A8 *c;
} G_1350A8;
typedef struct {
    u8 pad0[0xC];
    s32 fC;
    u8 pad10[0x18 - 0x10];
    s32 f18;
    u8 pad1C[0x24 - 0x1C];
    s32 (*f24)();
    u8 pad28[0x30 - 0x28];
    s32 (*f30)();
    u8 pad34[0x3C - 0x34];
    s32 f3C;
    u8 pad40[0x48 - 0x40];
    s32 f48;
    u8 pad4C[0x54 - 0x4C];
    s32 f54;
    u8 pad58[0x60 - 0x58];
    s32 f60;
    s32 f64;
    u8 pad68[0x8C - 0x68];
    s32 f8C;
    long f90;
    s32 f98;
    s32 f9C;
    long fA0;
    s32 fA8;
    s32 fAC;
    s32 fB0;
    u8 padB4[0xC0 - 0xB4];
    s32 fC0;
    s32 fC4;
    s32 fC8[14];
    long f100;
    s32 f108;
    s32 f10C;
    s32 f110;
    s32 f114;
    s32 f118[4];
    u8 pad128[0x1C8 - 0x128];
    G_1350A8 g[3];
    Fb_1350A8 fb[9];
    u8 pad5A0[0x85C - 0x5A0];
    s32 f85C;
    s32 f860;
    s32 f864;
    void *f868;
} D_1350A8;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 padC[0x10 - 0xC];
    long f10;
    long f18;
    long f20;
    long f28;
    long f30;
    long f38;
    D_1350A8 *f40;
} M_1350A8;
extern char D_00152058[];
extern char D_00152008[];
extern char D_00152030[];
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_0013A0F8();
extern s32 func_0013A150_001350A8(void *, char *, ...);
extern void func_00135FD8();
extern u32 func_00136010();
extern void func_00134FD8();
extern s32 func_00135C60();
extern s32 func_00135E88();
extern s32 func_00135FF0();
extern s32 func_00136080();
extern s32 func_001360A8();
typedef struct { u8 pad[0xC4]; s32 xC4; u8 pad2[0x24]; s32 xEC; s32 xF0; s32 xF4; s32 xF8; } T_135C10;
typedef struct { u8 pad[0x40]; T_135C10 *x40; } S_135C10;
extern void func_001353A8(S_135C10 *);
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    u8 pC[0x98 - 0xC];
    s32 x98;
    u8 p9C[0xC0 - 0x9C];
    s32 xC0;
    u8 pC4[0x128 - 0xC4];
    s32 x128;
    u8 p12C[0x858 - 0x12C];
    s32 x858;
    u8 p85C[0x878 - 0x85C];
    s32 x878;
} S_135C60;
typedef struct {
    u8 p0[8];
    s32 x8;
    u8 pC[0x40 - 0xC];
    S_135C60 *x40;
} A_135C60;
extern void func_001352E0(S_135C60 *);
typedef struct { u8 pad[0x184]; s32 x184; } T_135E40;
typedef struct { u8 pad[0x40]; T_135E40 *x40; } S_135E40;
extern void func_00135818(S_135E40 *, s32, s32);
extern void func_00135988(S_135E40 *, s32, s32);
typedef struct { u8 pad[0x28]; s32 x28; } C_135E88;
typedef struct { u8 pad[0x1C8]; C_135E88 *a0; C_135E88 *b0; u8 p1[8]; C_135E88 *a1; C_135E88 *b1; u8 p2[8]; C_135E88 *a2; C_135E88 *b2; } T_135E88;
typedef struct { u8 pad[0x40]; T_135E88 *x40; } S_135E88;
typedef struct {
    u8 pad[0x28];
    s32 x28;
} Pic_135F08;
typedef struct {
    u8 pad[0x130];
    s32 x130;
    u8 pad134[0x50];
    s32 x184;
    u8 pad188[0x48];
    Pic_135F08 *x1D0;
    u8 pad1D4[0xC];
    Pic_135F08 *x1E0;
    u8 pad1E4[0xC];
    Pic_135F08 *x1F0;
} Dec_135F08;
extern char D_00152138[];
extern char D_00152158[];
extern s32 func_0013A0F8();
extern s32 func_00131398(Dec_135F08 *);
typedef struct { u32 x0; u32 x4; u32 x8; } S_136010;
extern s32 func_0013A0F8();
extern char D_00152178[];
typedef struct { u8 pad[0x40]; u8 *x40; } S_136080;
extern void func_0013A280(u8 *);
typedef struct { u8 pad[0x40]; u8 *x40; } S_1360A8;
extern void func_0013A368(u8 *);
typedef struct {
    u8 pad0[0xEC];
    u32 fEC;
    u8 padF0[4];
    int fF4;
    int fF8;
    u8 padFC[0x184 - 0xFC];
    int f184;
} S_1360D0;
typedef struct {
    u32 f0;
    u8 pad4[0xC - 4];
    int fC;
    int f10;
} In_1360D0;
int func_00124920(void);
int func_00124970(void);
typedef struct {
    u8 pad0[4];
    int f4;
    int f8;
    int fC;
    int f10;
    u8 pad14[4];
    long f18;
    long f20;
    int f28;
    int f2C;
    int f30;
    int f34;
    int f38;
    int f3C;
    int f40;
    int f44;
    int f48;
    int f4C;
    int f50;
    int f54;
    int f58;
    int f5C;
    int f60;
} In_136620;
typedef struct {
    long a;
    long b;
    long c;
} TS_136620;
typedef struct {
    u8 pad0[0x10];
    TS_136620 ts[2];
} Out_136620;
typedef struct {
    u8 pad0[8];
    int f8;
    u8 padC[0x8C - 0xC];
    int f8C;
    long f90;
    int f98;
    int f9C;
    long fA0;
    u8 padA8[0xC0 - 0xA8];
    int fC0;
    int fC4;
    int fC8;
    int fCC;
    int fD0;
    int fD4;
    int fD8;
    u8 padDC[0xE0 - 0xDC];
    int fE0;
    int fE4;
    u8 padE8[0xF0 - 0xE8];
    int fF0;
    int fF4;
    int fF8;
    u8 padFC[0x100 - 0xFC];
    long f100;
    int f108;
    u8 pad10C[0x128 - 0x10C];
    int f128;
    u8 pad12C[0x184 - 0x12C];
    int f184;
    u8 pad188[0x834 - 0x188];
    int f834;
    u8 pad838[0x868 - 0x838];
    Out_136620 *f868;
} S_136620;
extern char D_00152198[];
int func_00121718(char *buf, int n, const char *fmt, ...);
void func_00136D50();
void func_001360D0();
typedef struct {
    u8 pad0[4];
    int f4;
    int f8;
    u8 padC[0xC0 - 0xC];
    int fC0;
    u8 padC4[0x128 - 0xC4];
    int f128;
    u8 pad12C[0x130 - 0x12C];
    int f130;
    u8 pad134[0x184 - 0x134];
    int f184;
    u8 pad188[0x1CC - 0x188];
    int f1CC;
    u8 pad1D0[0x1DC - 0x1D0];
    In_136620 *f1DC;
    u8 pad1E0[0x1EC - 0x1E0];
    In_136620 *f1EC;
} S_136A40;
typedef struct {
    u8 pad0[8];
    int f8;
    u8 padC[0x40 - 0xC];
    S_136A40 *f40;
} O_136A40;
extern char D_001521C8[];
extern void func_00136360(S_136A40 *s, int a, int b);
void func_00136620(S_136620 *s, In_136620 *a1, In_136620 *a2, int n);
typedef struct {
    u8 pad0[0x108];
    s32 f108;
    u8 pad10C[0x160 - 0x10C];
    s32 f160;
    u8 pad164[0x184 - 0x164];
    s32 f184;
    u8 pad188[0x1C8 - 0x188];
    s32 f1C8;
    u8 pad1CC[0x1D4 - 0x1CC];
    s32 f1D4;
    u8 pad1D8[0x1D8 - 0x1D8];
    s32 f1D8;
    u8 pad1DC[0x1E4 - 0x1DC];
    s32 f1E4;
    u8 pad1E8[0x1E8 - 0x1E8];
    s32 f1E8;
    u8 pad1EC[0x1F4 - 0x1EC];
    s32 f1F4;
} S_136B00;
typedef struct {
    u64 buf;
    u64 pos;
    u32 x10;
    u8 *ptr;
    s32 bits;
    u8 *start;
    u8 *end;
} BS_137450;
typedef struct {
    u64 buf;
    u64 pos;
    u32 x10;
    u8 *ptr;
    s32 bits;
    u8 *start;
    u8 *end;
} BS_137620;
typedef struct {
    u32 ext;
    u32 scr;
    u32 scr_hi;
    u32 sys;
} PH_137620;
extern void func_00137450_00137620(BS_137620 *, PH_137620 *);
typedef struct {
    unsigned long buf;   
    unsigned long pos;   
    u8 *base;            
    u8 *ptr;             
    s32 cnt;             
    u8 *top;             
    u8 *end;             
    s32 size;            
} BS_137CC8;
typedef struct {
    unsigned long id;    
    u32 len;             
    u32 scr;             
    unsigned long pts;   
    unsigned long dts;   
    u32 datapos;         
    s32 datalen;         
    u32 pktpos;          
} PES_137CC8;
typedef struct { u8 b[16]; } T16_137CC8;
extern const T16_137CC8 D_00152200;
extern char D_00152210[];
extern s32 func_00124920(void);
extern s32 func_00124970(void);
typedef struct { u8 pad[0xC]; s32 xC; u8 pad2[0x858]; s32 x868; } S_13A0F8;
extern s32 func_00135D50(s32, s32 *);
extern s32 func_00139F80(s32);
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern void func_0013A208(s32);
extern void func_0013A190(s32);
typedef struct {
    u32 d4madr;     
    u32 d4tadr;     
    u32 d4qwc;      
    u32 d4chcr;     
    u32 d3madr;     
    u32 d3qwc;      
    u32 d3chcr;     
    u32 ipubp;      
} E_13A368;
extern void func_0013A190_0013A368(u32);
extern void func_0013A208_0013A368(u32);
typedef int u128_13A598 __attribute__((mode(TI)));
extern volatile u128_13A598 D_001417B0[];
extern u128_13A598 D_00141800[];
void func_0013A520(int x);
#define IPU_CMD_13A598 (*(volatile u32 *)0x10002000)
#define IPU_CTRL_13A598 (*(volatile s32 *)0x10002010)
#define IPU_IN_13A598 (*(volatile u128_13A598 *)0x10007010)
extern s8 D_00141838_0013A7D0[];
extern char D_00152270_0013A7D0[];
extern s32 func_00123430();
extern void func_00123840();
extern void func_001236C0();
extern u8 D_00141838[];
extern void func_0013A7D0_0013A840(void);
extern s32 func_0013A840(void);
extern void func_0011EED0(u32 *);
extern u8 D_00141834[];
extern s32 func_0013A840(void);
extern void func_0011EED0(u32 *);
extern u8 D_00141832[];
extern s16 D_00141830[];
extern s32 func_0013A840(void);
extern void func_0011EED0(u32 *);
extern s32 func_0013A840(void);
extern void func_0011EED0(u32 *);
extern s32 func_0011F130(u8 *, s32, s32);
extern u8 D_00141836[];
typedef struct {
    u8 x0;
    u8 x1;
    u8 x2;
    u8 x3;
    u8 x4;
    u8 x5;
    u8 x6;
    u8 x7;
} S_13AA40;
typedef struct {
    s8 d[12];
} Days_13AB10;
extern Days_13AB10 D_00152280;
extern void func_0013ACC8(void *, s32);

ASM_FUNC("asm/boot_elf/handwritten", func_0013ADA8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013AFE8);

ASM_FUNC("asm/boot_elf/handwritten", func_0013AFF0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013AFF8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013B0C8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013B208);

extern u8 D_001D551D;
extern char D_001D4D90[];
extern char D_001D4D98[];
extern void func_001260D0(void);
extern s32 func_0011B9A0(char *, char *, s32);
extern s32 func_0011B610(char *, char *);
extern void func_0013B208(char *);
extern void *func_0013AFF8(void);
extern void func_0011F0A0(s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013B330);

typedef struct { s32 a; s32 pad; long b; } E_13C578;
extern s32 D_001D4E18;
extern s32 *D_001D4DC0[2];
extern s32 D_001D4DC8[2];
extern E_13C578 *D_001D4DD0[2];
extern u8 *D_001D4DD8[2];
extern s32 D_001D4DE8;
extern s32 D_001D4DF0;
extern long D_001D4DF8;
typedef struct { s32 a, b; } S_1D4900;
extern S_1D4900 D_1D4900;
extern S_1D4900 D_1D49C0;
extern s32 D_1D4980;
extern s32 D_1D4990_0013B3F8;
extern s32 D_1D4A00;
extern u8 D_15C3C0[];
extern u8 D_15D3C0[];
extern u8 D_15E3C0[];
extern u8 D_15F3C0[];
extern u8 D_1603C0[];
extern u8 D_160800[];
extern char D_001D4E20[];
extern char D_001D4E48[];
extern void func_00121FE8(s32);
extern s32 func_00122630(void *, s32, s32);
extern void func_0011AF48();
extern s32 func_0013C348(s32, s32, void *);
INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013B3F8);

typedef struct { void (*fn)(s32, long); s32 pad; long arg; } E_13B620;
extern s32 *D_001D4DA0;
extern s32 D_001D4DB0;
extern s32 D_001D4DB4;
extern s32 D_001D4DB8;
extern s32 D_001D4DBC;
extern s32 *D_001D4DC0[2];
extern E_13B620 *D_001D4DD0_0013B620[2];
extern u8 *D_001D4DD8[2];
extern s32 D_001D4DE0;
extern s32 D_001D4DE4;
extern s32 D_001D4DE8;
extern s32 D_001D4DF0;
extern long D_001D4DF8;
extern s32 D_1D4A00;
extern void (*D_001D4E04)(s32, long);
extern long D_001D4E08;
extern s32 func_0013B818(void);
extern void func_11F0A0(s32);
extern void func_0013C908(void);
extern s32 func_0013CDF0(s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013B620);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013B808);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013B810);

/* PAL candidate for func_0013B818 (boot_elf, src/boot_elf/core/13ADA8.c).
   Retail builds the address of D_1D4900 with lui/addiu (one macro, adjacent,
   same register), while the sized alias D_1D4900_0013B818 (s32[2]) would be
   reached through $gp.  The per-function alias plus a size hint over 8 keeps
   retail's lui/addiu under the file's own flags (no @ps2as), and the single
   macro also keeps gcc from splitting the pair over two delay slots, which is
   what made it emit bnel instead of retail's beqz. */

/* localdecomp:start func_0013B818 */
__asm__(".extern D_001D4DA0, 4");
__asm__(".extern D_001D4DA4, 4");
__asm__(".extern D_001D4E18, 4");
/* the size hint over 8 keeps the assembler from making this small data:
   retail builds the address with lui/addiu (one macro), not with $gp */
__asm__(".extern D_1D4900_0013B818_l, 16");
extern s32 D_001D4DA4;
extern s32 *D_001D4DA0;
extern s32 D_001D4E18;
extern s32 D_1D4900_0013B818_l[2];
extern char D_00152290[];
extern void func_0011F0A0(s32);
extern s32 func_00122A10(void *);
extern s32 func_0011AF48_0013B818(const char *, ...);
s32 func_0013B818(void) {
    s32 *p;
    func_0011F0A0(0);
    if (D_001D4DA0 == 0) return 1;
    if (func_00122A10(D_1D4900_0013B818_l) != 0) return 0;
    p = D_001D4DA0;
    if ((u32)p[0] == 0xFFFFFFFF && p[D_001D4DA4 + 1] == p[0]) {
        D_001D4DA0 = 0;
        return 1;
    }
    if (D_001D4E18 == 0) func_0011AF48_0013B818(D_00152290);
    return 0;
}
/* localdecomp:end func_0013B818 */

/* localdecomp:start func_0013B8B0 */
extern s32 D_001D4DA4;
extern s32 *D_001D4DA0;
extern void func_0011F698(void *, void *);
void func_0013B8B0(s32 *p, s32 n) {
    D_001D4DA4 = n;
    D_001D4DA0 = p;
    p[n + 1] = 0;
    p[0] = 0;
    func_0011F698(p, (u8 *)p + 3);
    p = &p[n + 1];
    func_0011F698(p, (u8 *)p + 3);
}
/* localdecomp:end func_0013B8B0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013B910);

extern s32 D_001D4DA8;
extern s32 D_001D4DE8;
extern s32 D_001D4E18;
extern s32 D_1D4A00;
extern s32 D_1D4A04;
extern s32 D_1D4A40;
extern u8 D_1D49C0_0013BAB8[8];
extern char D_001D4F20[];
extern char D_001D4F50[];
extern char D_001D4F70[];
extern char D_001D4E98[];
extern void func_0011AF48_0013BAB8(char *);
extern s32 func_0013CDF0(s32);
extern void func_0011F698(void *, void *);
extern s32 func_00122A10(void *);
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_11F0A0(s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013B918);

extern s32 D_001D4DA8;
extern s32 D_001D4DE8;
extern s32 D_001D4E18;
extern s32 D_001D4DF0;
extern s32 D_1D4A00;
extern s32 D_1D4A04;
extern s32 D_1D4A40;
extern s32 D_1D4A44;
extern u8 D_1D49C0_0013BAB8[8];
extern char D_001D4F20[];
extern char D_001D4F50[];
extern char D_001D4F70[];
extern char D_001D4E98[];
extern void func_0011AF48_0013BAB8(char *);
extern s32 func_0013CDF0(s32);
extern void func_0011F698(void *, void *);
extern s32 func_00122A10(void *);
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_11F0A0(s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013BAB8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013BC28);

extern s32 D_001D4DA8;
extern s32 D_1D4A04;
extern s32 D_1D4A40;
extern char D_001D5018[];
extern void func_0011F698(void *, void *);
extern char D_001D4E98[];
extern s32 func_00122A10();
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_0011F0A0(s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013BC30);

extern s32 D_001D4DA8;
extern s32 D_001D4DE8;
extern s32 D_001D4E18;
extern s32 D_1D4A00;
extern s32 D_1D4A04;
extern s32 D_1D4A40;
extern char D_001D5050[];
extern char D_001D5080[];
extern char D_001D4E98[];
extern void func_0011AF48();
extern void func_0011F698(void *, void *);
extern s32 func_00122A10();
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_0011F0A0(s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013BD58);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013BEB0);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013BEC8);

/* localdecomp:start func_0013BED0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013BED0(void) {
    return func_0013C578(0x8, 0, 0, 0, 0);
}
/* localdecomp:end func_0013BED0 */

/* localdecomp:start func_0013BF00 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013BF00(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x6, 4, buf, 0, 0);
}
/* localdecomp:end func_0013BF00 */

/* localdecomp:start func_0013BF30 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013BF30(s32 a, s32 b) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    return func_0013C578(0x9, 8, buf, 0, 0);
}
/* localdecomp:end func_0013BF30 */

/* localdecomp:start func_0013BF68 */
typedef struct { u8 b[0x18]; } V_13BF68;
typedef struct { s32 a; V_13BF68 v; } B_13BF68;
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013BF68(s32 a, V_13BF68 *p) {
    B_13BF68 buf;
    buf.a = a;
    if (p != 0) {
        buf.v = *p;
    } else {
        *(s32 *)&buf.v = -1;
    }
    return func_0013C578(0x60, 0x1C, &buf, 0, 0);
}
/* localdecomp:end func_0013BF68 */

/* localdecomp:start func_0013BFE0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013BFE0(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0xB, 4, buf, 0, 0);
}
/* localdecomp:end func_0013BFE0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C010);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C020);

/* localdecomp:start func_0013C028 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C028(s32 a, s32 b, s32 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    return func_0013C578(0x4E, 0xC, buf, 0, 0);
}
/* localdecomp:end func_0013C028 */

/* localdecomp:start func_0013C068 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C068(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x64, 4, buf, 0, 0);
}
/* localdecomp:end func_0013C068 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C098);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C0B0);

/* localdecomp:start func_0013C0B8 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C0B8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    s32 buf[6];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    buf[5] = f;
    return func_0013C578(0x11, 0x18, buf, g, h);
}
/* localdecomp:end func_0013C0B8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C100);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C110);

/* localdecomp:start func_0013C118 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C118(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x15, 4, buf, 0, 0);
}
/* localdecomp:end func_0013C118 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C148);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C168);

/* localdecomp:start func_0013C170 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C170(void) {
    return func_0013C578(0x18, 0, 0, 0, 0);
}
/* localdecomp:end func_0013C170 */

/* localdecomp:start func_0013C1A0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C1A0(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x16, 4, buf, 0, 0);
}
/* localdecomp:end func_0013C1A0 */

/* localdecomp:start func_0013C1D0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C1D0(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x17, 4, buf, 0, 0);
}
/* localdecomp:end func_0013C1D0 */

/* localdecomp:start func_0013C200 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C200(s32 a, s32 b, long c) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x19, 4, buf, b, c);
}
/* localdecomp:end func_0013C200 */

/* localdecomp:start func_0013C230 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C230(s32 a, s32 b, s32 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    return func_0013C578(0x1B, 0xC, buf, 0, 0);
}
/* localdecomp:end func_0013C230 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C270);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C298);

/* localdecomp:start func_0013C2A0 */
extern s32 func_0013C2C0(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_0013C2A0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    return func_0013C2C0(a, b, c, d, e, f, 0, 0);
}
/* localdecomp:end func_0013C2A0 */

/* localdecomp:start func_0013C2C0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C2C0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    s32 buf[6];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    buf[5] = f;
    return func_0013C578(0x21, 0x18, buf, g, h);
}
/* localdecomp:end func_0013C2C0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C308);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C340);
