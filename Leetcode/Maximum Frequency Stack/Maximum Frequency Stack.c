//C program for Maximum Frequency Stack

// Below are part of sys/mman.h, but for some reason(platform macro disabled?), these
// don't look like accessible even if that's included. So, defining these myself here
// based on their original values.
#define PROT_READ           0x1
#define PROT_WRITE          0x2
#define MAP_ANONYMOUS       0x20  
#define MAP_PRIVATE         0x02
#define MAP_FAILED          ((void *)-1)
extern void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

#define ALL_SZ              10000            
#define ONEG                (1024 * 1024 * 1024ULL)

typedef struct {
    uint16_t t[ALL_SZ], m[ONEG], mxf;
    int fm[ALL_SZ][ALL_SZ];
} FreqStack;

FreqStack* freqStackCreate() { // Though usual malloc, calloc, would internally call mmap() for
    // large allocations such as this, for some reason, it didn't or failed in doing so. So, I am
    // directly using mmap() myself for doing the needed anonymous memory allocation.
    return mmap(NULL, sizeof(FreqStack), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}

void freqStackPush(FreqStack* obj, int x) {

    // f is declared as obj
    FreqStack *f = obj;
    int fq = ++f->m[x];
    f->fm[fq][++f->t[fq]] = x;
    f->mxf < f->m[x] ? f->mxf = f->m[x] : 0;
}

int freqStackPop(FreqStack* obj) {
    FreqStack *f = obj;
    int val = f->fm[f->mxf][f->t[f->mxf]--];
    f->m[val]--;
    !f->t[f->mxf] ? f->mxf-- : 0;
    //return value
    return val;
}

void freqStackFree(FreqStack* obj) {
    munmap(obj);
}

