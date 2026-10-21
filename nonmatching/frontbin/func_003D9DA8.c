/* US draft of func_003D9DA8 (rac3-uya-decomp func_003D4858, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003D9DA8 */
typedef struct {
    u8 pad[0x7614];
    s32 value;
} SourceBlock_003D4858;
extern u8 *D_001DA704;
extern u8 *D_001DA708;
extern s32 D_001DA710;
extern s32 D_001DA728;
extern s32 D_001DA72C;
extern s32 D_001DA730;
extern u8 *D_001DA734;
__asm__(".extern D_001DA704, 16");
__asm__(".extern D_001DA708, 16");
__asm__(".extern D_001DA710, 16");
__asm__(".extern D_001DA728, 16");
__asm__(".extern D_001DA72C, 16");
__asm__(".extern D_001DA734, 16");
void func_003D9DA8(void) {
    register SourceBlock_003D4858 *source_block __asm__("$3") = (SourceBlock_003D4858 *)0x220000;
    register u8 *buffer __asm__("$2") = (u8 *)0x300000;
    s32 source;
    register u8 *entry __asm__("$5");
    register u8 *end __asm__("$3");
    __asm__ volatile("" : "+r"(source_block), "+r"(buffer));
    source = source_block->value;
    buffer -= 0x42C0;
    entry = D_001DA704;
    end = D_001DA708;
    D_001DA710 = source;
    D_001DA734 = buffer;
    D_001DA728 = 0;
    D_001DA72C = 0;
    D_001DA730 = 0;
    if (entry != end) {
        register u16 empty __asm__("$4") = 0xFFFF;
        register u8 marker __asm__("$3") = 0xFF;
        do {
            entry[0x1F] = marker;
            *(s16 *)(entry + 0x16) = 0;
            *(u16 *)(entry + 0x14) = empty;
            buffer = D_001DA708;
            __asm__ volatile("" : "+r"(buffer));
            entry += 0x20;
        } while (entry != buffer);
    }
}
/* localdecomp:end func_003D9DA8 */
