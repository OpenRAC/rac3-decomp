/* functional: high. BIO_ctrl-style dispatch; retail structure identical, diff is only frame/scheduling. Caller context declares it with s32 args, so the real signature (long ret, long larg) needs the callers' externs changed when ported. */
/* BIO_ctrl: method->ctrl (at +0x18) does the work; optional bio callback (at +4) runs before (cmd 6) and after (0x86) */
typedef struct M_004DAE48 {
    s32 pad[6];
    long (*ctrl)(void *, s32, long, void *);
} M_004DAE48;

typedef struct B_004DAE48 {
    M_004DAE48 *method;
    long (*cb)(void *, s32, void *, s32, long, long);
} B_004DAE48;

extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

long func_L39_004DAE48(B_004DAE48 *bio, s32 cmd, long larg, void *parg) {
    long ret;
    long (*cb)(void *, s32, void *, s32, long, long);

    if (bio == 0) {
        return 0;
    }
    if (bio->method == 0 || bio->method->ctrl == 0) {
        func_L39_004BC6C8(0x20, 0x65, 0x6F, 0, 0);
        return -2;
    }
    cb = bio->cb;
    if (cb != 0) {
        ret = cb(bio, 6, parg, cmd, larg, 1);
        if (ret <= 0) {
            return ret;
        }
    }
    ret = bio->method->ctrl(bio, cmd, larg, parg);
    if (cb != 0) {
        ret = cb(bio, 0x86, parg, cmd, larg, ret);
    }
    return ret;
}
