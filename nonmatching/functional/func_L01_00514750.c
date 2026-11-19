/* functional: high. Near-miss draft; instruction multiset equals retail (5 words are prologue scheduling only). */
/* localdecomp:start func_L01_00514750 */
static __inline__ s32 *button_addr_00514750(D_001A4BE0_t *hero) {
    return (s32 *)((u8 *)hero + 0x25F8);
}
s32 func_L01_00514750(s32 *input) {
    s32 changed=0;
    s32 *dest=button_addr_00514750(&D_001A4BE0);
    s32 *previous=&D_001D4C40;
    s32 i;
    for(i=3;i>=0;i--) {
        if(*previous!=*input) {
            changed=1;
            *dest=*input ? *input : 0xCC;
        }
        dest++;input++;previous++;
    }
    return changed;
}
/* localdecomp:end func_L01_00514750 */
