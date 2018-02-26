#include <iostream>

class CMyString {
public:
    CMyString(char *pData = NULL);

    CMyString(const CMyString &str);

    ~CMyString(void);

    // void operator=(const CMyString &other) {    /// use const ref to avoid in-func modification
    CMyString &
    operator=(const CMyString &other) {  /// return **reference** to allow continuing assignment( assignment chaining).
        if (this == &other) {   /// check if same!
            return *this;
        }
        delete[] m_pData;   /// NOTE mem leak!
        m_pData = nullptr;
        m_pData = new char[strlen(other.m_pData) + 1];  /// NOTE +1 !
        strcpy(m_pData, other.m_pData);

        return *this;
    }

private:
    char *m_pData;
};

CMyString::CMyString(char *pData) {
    if (pData == NULL) m_pData = nullptr;
    else {
        // deep copy?
    }
}

CMyString::CMyString(const CMyString &str) {
    // do deep copy?
}


/// 1. should allocate another block of memory and copy data to it,
///    or simply assign pointer value and allow two pointers to point to same block of mem?
/// 2. if deep copy, how to allocate mem?