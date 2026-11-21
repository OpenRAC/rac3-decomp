/* functional: high. Draft read against asm: vtable (arg0+8) slot 0x10 called with (arg0, D_001D97C0 [gp-0x30F0]); on nonzero copies 16 bytes D_001D96C0 to a local, calls slot 0x20 (arg0,&v,out,1), stores out[0..3] to arg1..arg4 (note arg4 is in $a4/$t0 register), returns 1; else 0. The snippet declares D_001D97C0_003EBE58/D_001D96C0 as in the draft. 33 words differ (unaligned 16-byte copy ldl/ldr vs lq, schedule). */
typedef struct { u8 b[16]; } V16_003E6538;
extern s32 D_001D97C0_003EBE58;
extern V16_003E6538 D_001D96C0;
s32 func_003EBE58(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_003E6538 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D97C0_003EBE58) != 0) {
        v = D_001D96C0;
        (*(s32 (**)(void *, void *, f32 *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x20))(arg0, &v, out, 1);
        *arg1 = out[0];
        *arg2 = out[1];
        *arg3 = out[2];
        *arg4 = out[3];
        return 1;
    }
    return 0;
}
