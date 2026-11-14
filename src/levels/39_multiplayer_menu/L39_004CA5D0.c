#include "common.h"

/* localdecomp:start func_L39_004CA5D0 */
typedef struct C_004CA5D0 {
    s32 valid;
    char *name;
    unsigned long id;
    unsigned long algorithms;
    unsigned long algorithm2;
    unsigned long mask;
} C_004CA5D0;

typedef struct St_004CA5D0 {
    s32 num;
    char **data;
} St_004CA5D0;

typedef struct M_004CA5D0 {
    u8 pad[0x44];
    s32 (*num_ciphers)(void);
    C_004CA5D0 *(*get_cipher)(u32);
} M_004CA5D0;

typedef struct O_004CA5D0 {
    C_004CA5D0 *cipher;
    s32 active;
    s32 dead;
    struct O_004CA5D0 *next;
    struct O_004CA5D0 *prev;
} O_004CA5D0;

typedef struct Ch_004CA5D0 {
    char *name;
    s32 type;
    unsigned long algorithms;
    unsigned long mask;
    s32 exact;
    unsigned long id;
} Ch_004CA5D0;

extern s32 func_00120B70(char *, char *, s32);
extern s32 func_00120884(char *);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern char *func_001202F4(char *, char *);
extern s32 func_001205B0(char *, char *);
extern void func_0011D534(void *, s32, s32);
extern void func_L39_004CA328(void);
extern s32 func_L39_004C4F30(s32);
extern St_004CA5D0 *func_L39_004CC228(void *);
extern s32 func_L39_004CC3E0(St_004CA5D0 *, void *);
extern s32 func_L39_004CC2C8(St_004CA5D0 *, void *);
extern void func_L39_004CC538(St_004CA5D0 *);
extern St_004CA5D0 *func_L39_004CC190(St_004CA5D0 *);
extern void func_L39_004CC178(St_004CA5D0 *, void *);
extern void func_L39_004CA568(O_004CA5D0 **, O_004CA5D0 *, O_004CA5D0 **);
extern s32 func_L39_004CA2C0();
extern s32 func_L39_004CA2E8();
extern s32 D_L39_004C4130[];
extern char D_L39_00475DC0[];
extern char D_L39_00475DC8[];
extern char D_L39_00475DF8[];
extern s32 D_L39_004656F8 __attribute__((section(".data")));
extern s32 D_L39_00465108[];
extern s32 D_L39_00465128[];
extern C_004CA5D0 D_L39_00465130[];

/* from OpenSSL 0.9.4's ssl_create_cipher_list (ssl/ssl_ciph.c), with this build's changes */
St_004CA5D0 *func_L39_004CA5D0(M_004CA5D0 *ssl_method, St_004CA5D0 **cipher_list,
                               St_004CA5D0 **cipher_list_by_id, char *str) {
    C_004CA5D0 *c;
    char *l;
    St_004CA5D0 *ret = 0, *ok = 0;
    char buf[40];
    char *tmp_str = 0;
    unsigned long mask, algorithms, ma, id;
    s32 i, j, k, num = 0, ch, multi;
    unsigned long al;
    St_004CA5D0 *ca_list = 0;
    St_004CA5D0 *ca_id = 0;
    s32 current_x, num_x;
    Ch_004CA5D0 *ops = 0;
    O_004CA5D0 *list = 0, *head = 0, *tail = 0, *curr, *tail2, *curr2;
    s32 list_num;
    s32 type;
    s32 exact;
    s32 op;
    char *name;
    C_004CA5D0 c_tmp, *cp;

    if (str == 0) return 0;

    if (func_00120B70(str, D_L39_00475DC0, 7) == 0) {
        i = func_00120884(str) + 2 + 47;
        if ((tmp_str = func_L39_004BEED8(i)) == 0) {
            func_L39_004BC6C8(0x14, 0xA6, 0x21, 0, 0);
            goto err;
        }
        __builtin_memcpy(tmp_str, D_L39_00475DC8, 48);
        func_001202F4(tmp_str, D_L39_00475DF8);
        func_001202F4(tmp_str, &str[7]);
        str = tmp_str;
    }
    if (D_L39_004656F8) func_L39_004CA328();

    mask = 8;
    mask |= (func_L39_004C4F30(2) == 0) ? 0x40 : 0;
    mask |= (func_L39_004C4F30(1) == 0) ? 0x216 : 0;
    mask |= (func_L39_004C4F30(4) == 0) ? 0x10000 : 0;
    mask |= (func_L39_004C4F30(8) == 0) ? 0x100 : 0;

    mask |= (D_L39_00465108[0] == 0) ? 0x400 : 0;
    mask |= (D_L39_00465108[1] == 0) ? 0x800 : 0;
    mask |= (D_L39_00465108[2] == 0) ? 0x1000 : 0;
    mask |= (D_L39_00465108[3] == 0) ? 0x2000 : 0;
    mask |= (D_L39_00465108[4] == 0) ? 0x4000 : 0;
    mask |= (D_L39_00465108[5] == 0) ? 0x8000 : 0;

    mask |= (D_L39_00465128[0] == 0) ? 0x20000 : 0;
    mask |= (D_L39_00465128[1] == 0) ? 0x40000 : 0;

    num = ssl_method->num_ciphers();

    if ((ret = func_L39_004CC228(0)) == 0) goto err;
    if ((ca_list = func_L39_004CC228(func_L39_004CA2C0)) == 0) goto err;
    if ((ca_id = func_L39_004CC228(func_L39_004CA2E8)) == 0) goto err;

    if ((list = func_L39_004BEED8(sizeof(O_004CA5D0) * num + 1)) == 0) goto err;

    list_num = 0;
    for (i = 0; i < num; i++) {
        c = ssl_method->get_cipher(i);
        if ((c != 0) && c->valid && !(c->algorithms & mask)) {
            list[list_num].cipher = c;
            list[list_num].next = 0;
            list[list_num].prev = 0;
            list[list_num].active = 0;
            list_num++;
            if (!func_L39_004CC3E0(ca_list, c)) goto err;
            if (!func_L39_004CC3E0(ca_id, c)) goto err;
        }
    }

    for (i = 1; i < list_num - 1; i++) {
        list[i].prev = &list[i - 1];
        list[i].next = &list[i + 1];
    }
    if (list_num > 0) {
        head = &list[0];
        head->next = &list[1];
        head->prev = 0;
        tail = &list[list_num - 1];
        if (list_num < 2)
            tail->prev = 0;
        else
            tail->prev = &list[list_num - 2];
        tail->next = 0;
    }

    D_L39_00465130[0].algorithms = ~mask;

    k = 37;
    for (j = 0; j < k; j++) {
        al = D_L39_00465130[j].algorithms;
        if ((al & mask) == al) continue;
        if (!func_L39_004CC3E0(ca_list, &D_L39_00465130[j])) goto err;
    }

    num = 1;
    for (l = str; *l; l++)
        if (*l == ':' || *l == ' ' || *l == ';' || *l == ',')
            num++;
    ops = func_L39_004BEED8(sizeof(Ch_004CA5D0) * num);
    if (ops == 0) goto err;
    func_0011D534(ops, 0, sizeof(Ch_004CA5D0) * num);

    l = str;
    current_x = 0;

    for (;;) {
        ch = *l;

        if (ch == '\0') break;

        if (ch == '-') {
            op = 3; l++;
        } else if (ch == '+') {
            op = 4; l++;
        } else if (ch == '!') {
            op = 2; l++;
        } else {
            op = 1;
        }

        if (ch == ':' || ch == ' ' || ch == ';' || ch == ',') {
            l++;
            continue;
        }

        for (;;) {
            ch = *l;
            i = 0;
            while (((ch >= 'A') && (ch <= 'Z')) ||
                   ((ch >= '0') && (ch <= '9')) ||
                   ((ch >= 'a') && (ch <= 'z')) ||
                   (ch == '-')) {
                buf[i] = ch;
                ch = *(++l);
                i++;
                if (i >= 38) break;
            }
            buf[i] = '\0';

            if (ch == '+') {
                multi = 1;
                l++;
                if (!(((*l >= 'A') && (*l <= 'Z')) ||
                      ((*l >= '0') && (*l <= '9')) ||
                      ((*l >= 'a') && (*l <= 'z')) ||
                      (*l == '-'))) {
                    while (!(*l == ':' || *l == ' ' || *l == ';' || *l == ',') && *l != '\0') l++;
                    goto end_loop;
                }
            } else {
                multi = 0;
                if (!((*l == ':' || *l == ' ' || *l == ';' || *l == ',') || *l == '\0') || i == 0) {
                    while (!(*l == ':' || *l == ' ' || *l == ';' || *l == ',') && *l != '\0') l++;
                    goto end_loop;
                }
            }

            c_tmp.name = buf;
            j = func_L39_004CC2C8(ca_list, &c_tmp);
            if (j < 0) {
                char *p = buf;
                unsigned long v = 0;
                if (buf[0] == '0' && buf[1] == 'x') p = buf + 2;
                while (*p) {
                    v <<= 4;
                    if (*p >= '0' && *p <= '9') v += *p - '0';
                    else if (*p >= 'A' && *p <= 'F') v += *p - 'A' + 10;
                    else if (*p >= 'a' && *p <= 'f') v += *p - 'a' + 10;
                    else goto end_loop;
                    p++;
                }
                c_tmp.id = v;
                j = func_L39_004CC2C8(ca_id, &c_tmp);
                if (j < 0) goto end_loop;
                cp = (C_004CA5D0 *)ca_id->data[j];
                ops[current_x].id = cp->id;
            } else {
                cp = (C_004CA5D0 *)ca_list->data[j];
                ops[current_x].id = 0;
            }
            ops[current_x].type = op;
            ops[current_x].name = cp->name;
            ops[current_x].algorithms |= cp->algorithms;
            ops[current_x].mask |= cp->mask;
            ops[current_x].exact = (cp->valid == 1);
            if (!multi || ops[current_x].exact) break;
        }
        current_x++;
        if (ch == '\0') break;
end_loop:
        while ((*l != '\0') && (*l == ':' || *l == ' ' || *l == ';' || *l == ','))
            l++;
    }

    num_x = current_x;
    current_x = 0;

    for (j = 0; j < num_x; j++) {
        algorithms = ops[j].algorithms;
        type = ops[j].type;
        mask = ops[j].mask;
        name = ops[j].name;
        exact = ops[j].exact;
        id = ops[j].id;

        curr = head;
        curr2 = head;
        tail2 = tail;
        for (;;) {
            if ((curr == 0) || (curr == tail2)) break;
            curr = curr2;
            curr2 = curr->next;

            cp = curr->cipher;
            if (exact && func_001205B0(name, cp->name)) continue;
            if (id && cp->id != id) continue;
            ma = mask & cp->algorithms;
            if ((ma == 0) || ((ma & algorithms) != ma)) continue;

            if (type == 1) {
                if (!curr->active) {
                    func_L39_004CA568(&head, curr, &tail);
                    curr->active = 1;
                }
            } else if (type == 4) {
                if (curr->active) {
                    func_L39_004CA568(&head, curr, &tail);
                }
            } else if (type == 3)
                curr->active = 0;
            if (type == 2) {
                if (head == curr)
                    head = curr->next;
                else
                    curr->prev->next = curr->next;
                if (tail == curr)
                    tail = curr->prev;
                curr->active = 0;
                if (curr->next != 0)
                    curr->next->prev = curr->prev;
                if (curr->prev != 0)
                    curr->prev->next = curr->next;
                curr->next = 0;
                curr->prev = 0;
            }
        }
    }

    for (curr = head; curr != 0; curr = curr->next) {
        if (curr->active) {
            func_L39_004CC3E0(ret, curr->cipher);
        }
    }

    if (cipher_list != 0) {
        if (*cipher_list != 0)
            func_L39_004CC538(*cipher_list);
        *cipher_list = ret;
        if (ret == 0) goto err;
    }

    if (cipher_list_by_id != 0) {
        if (*cipher_list_by_id != 0)
            func_L39_004CC538(*cipher_list_by_id);
        if ((*cipher_list_by_id = func_L39_004CC190(ret)) == 0) goto err;
        func_L39_004CC178(*cipher_list_by_id, D_L39_004C4130);
    }

    ok = ret;
    ret = 0;
err:
    if (tmp_str) func_L39_004BEF28(tmp_str);
    if (ops != 0) func_L39_004BEF28(ops);
    if (ret != 0) func_L39_004CC538(ret);
    if (ca_list != 0) func_L39_004CC538(ca_list);
    if (ca_id != 0) func_L39_004CC538(ca_id);
    if (list != 0) func_L39_004BEF28(list);
    return ok;
}
/* localdecomp:end func_L39_004CA5D0 */
