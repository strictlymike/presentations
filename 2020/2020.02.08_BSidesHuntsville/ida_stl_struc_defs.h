/*****************************************************************************
 * These structure definitions are for use in IDA Pro or other disassemblers.
 *
 * To use this with IDA:
 *   1. Go to the Local Types for your IDA database 
 *   2. Insert a new type
 *   3. Paste the structures below
 *   4. Go to the Structures for your IDA database
 *   5. Add each structure, specifying its name; IDA will populate the
 *      definition based on the definition you pasted into Local Types.
 *
 * WARNING:
 * The definitions in this file are based on research and do not represent
 * authoritative or definitive structures for the corresponding concepts in
 * binary code.
 *****************************************************************************/

/*****************************************************************************
 * STL Structures based on VC headers - Michael Bailey, FireEye FLARE Team
 *****************************************************************************/

struct basic_string {
    union { /* union _Bxty */
        char _Buf[16];
        wchar_t _BufW[8];
        char * _Ptr;
        wchar_t *_PtrW;
    } _Bx;
    size_t _Mysize;
    size_t _Myres;
};

struct vector {
    void *_Myfirst;
    void *_Mylast;
    void *_Myend;
};

// Caveats
// * Struct header only
// * Older VC (e.g. 2008) place the value type between _Right and _Color
//
// The value type depends on map vs set
// * set: _Ty
// * map: pair<_Ty1, _Ty2>
//
// Suggested usage:
// * Define value type
// * Define node type composing node header with value type
//
// Example:
//  // Value type
//  struct pair_str_int {
//      basic_string s;
//      int n;
//  };
//
//  // Composite node type (header plus value type)
//  struct _Node34h_email_srctype {
//      struct _Node node;
//      struct pair_str_int val;
//  };
struct _Node {
    void *_Left;
    void *_Parent;
    void *_Right;
    char _Color;
    char _Isnil;
    short padding;
};

struct _Tree {
    struct _Node *_Myhead;
    size_t _Mysize;
};

