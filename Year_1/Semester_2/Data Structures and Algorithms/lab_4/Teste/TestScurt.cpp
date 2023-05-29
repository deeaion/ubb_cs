#include "TestScurt.h"
#include "../MD/MD.h"
#include "../Iterator/IteratorMD.h"
#include <assert.h>
#include <vector>
#include<iostream>
#include <string.h>
void testAll() {
	MD m;
	m.adauga(1, 100);
	m.adauga(2, 200);
	m.adauga(3, 300);
	m.adauga(1, 500);
	m.adauga(2, 600);
	m.adauga(4, 800);
    IteratorMD im2 = m.iterator();
    assert(im2.valid() == true);
    while (im2.valid()) {
        im2.element();
       // cout<<im2.element().second<<endl;
        im2.urmator();

    }
	assert(m.dim() == 6);

	assert(m.sterge(5, 600) == false);
	assert(m.sterge(1, 500) == true);

	assert(m.dim() == 5);

    vector<TValoare> v;
	v=m.cauta(6);
	assert(v.size()==0);

	v=m.cauta(1);
	assert(v.size()==1);

	assert(m.vid() == false);

	IteratorMD im = m.iterator();
	assert(im.valid() == true);
	while (im.valid()) {
		im.element();
		im.urmator();

	}
	assert(im.valid() == false);
	im.prim();
	assert(im.valid() == true);
    testRevinoPasi();
}
void testRevinoPasi()
{
    MD m;
    m.adauga(2, 200);
    m.adauga(2,400);
    m.adauga(2, 600);
    m.adauga(3, 300);
    m.adauga(6, 800);
    IteratorMD im = m.iterator();
    IteratorMD im2 = m.iterator();
    assert(im2.valid() == true);
    while (im2.valid()) {
        im2.element();
        cout<<im2.element().second<<endl;
        im2.urmator();

    }
    assert(im.valid() == true);
    im.urmator();
    cout<<im.element().second;
    assert(im.element().second==400);
    im.revinoKPasi(1);
    cout<<im.element().second;
    assert(im.element().second==200);
    im.urmator();
    assert(im.element().second==400);
    im.urmator();
    im.urmator();
    cout<<im.element().second;
    im.revinoKPasi(3);
    assert(im.element().second==200);
    try
    {im.revinoKPasi(1);}
    catch (std::invalid_argument &m)
    {
        assert(strcmp(m.what(),"Invalid number")==0);
    }


}