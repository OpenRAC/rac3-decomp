/* US draft of func_003BF058 (rac3-uya-decomp func_003B9B60, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003BF058 */
extern u8 D_001DA310;
extern u8 D_001DA311;
extern s32 D_001D8DF0;
extern s32 D_001D8DF4;
extern void *D_002FCC40;
extern void func_003BBA08(s32, s32);
extern void func_003BC408();
extern void func_003BDCB0(s32, s32 *, s32);
extern s32 func_003BDD38(void);
extern void func_003BDE20(s32);
extern void func_003BF2A0();
extern void func_003BF0E0();
extern void func_003BE308(void *);
extern void func_003BE1F8(s32);
__asm__(".extern D_001DA310, 16");
__asm__(".extern D_001DA311, 16");
__asm__(".extern D_001D8DF4, 16");
__asm__(".extern D_002FCC40, 16");
s32 func_003BF058(void) {
    register s32 first __asm__("$4") = 0;
    D_001DA310 = 0;
    D_001DA311 = 0;
    __asm__ volatile("" : : : "memory");
    {
        register s32 second __asm__("$5") = 0;
        func_003BBA08(first, second);
    }
    func_003BC408(4, &D_001D8DF0);
    func_003BDCB0(3, &D_001D8DF4, D_001D8DF0);
    func_003BDE20(func_003BDD38());
    {
        register u8 *callback __asm__("$2") = (u8 *)0x3C0000;
        register u8 *slot_base __asm__("$3") = (u8 *)0x300000;
        register u8 *handler __asm__("$4");
        __asm__ volatile("" : "+r"(callback), "+r"(slot_base));
        callback -= 0x6258;
        handler = (u8 *)0x3C0000;
        __asm__ volatile("" : "+r"(handler));
        *(void **)(slot_base - 0x7340) = callback;
        handler -= 0x6418;
        func_003BE308(handler);
    }
    func_003BE1F8(1);
    return 1;
}
/* localdecomp:end func_003BF058 */
