#include "dibwnd.h"
//#include "include/ptr.h"

BOOL CDIBWnd::Init( HWND hWnd, Ptr<CDIB> const& dib, int cx, int cy ) {
    if ( hWnd == NULL || dib.Value() == NULL) {
        return FALSE;
    }
    m_hWnd = hWnd;
    m_ptrdib = dib;
    return TRUE;
}

void CDIBWnd::Exit() {}

BOOL CDIBWnd::Size( LPARAM lParam ) {
    return FALSE;
}

BOOL CDIBWnd::Size( int cx, int cy ) {
    return FALSE;
}

void CDIBWnd::Paint( CRect rect ) {
}

void CDIBWnd::Invalidate( RECT const* pRect ) const {
}

void CDIBWnd::Invalidate( int iLeft, int iTop, int iRight, int iBottom ) const {
}

void CDIBWnd::Update() const {
}

void CDIBWnd::ctor() {}

//--------------------------- C D i r t y R e c t s -----------------------------
//
// Handles dirty rects for a CDibWnd

CDirtyRects::CDirtyRects( CDIBWnd* dibwnd ) {
}

void CDirtyRects::UpdateLists() {
}

void CDirtyRects::BltRects() {
    
}

void CDirtyRects::AddRect( CRect const* prect, CDirtyRects::RECT_LIST eList ) {
}

void CDirtyRects::AddRect( CRect const* prect, CRect arect[], int& unk ) {
}
