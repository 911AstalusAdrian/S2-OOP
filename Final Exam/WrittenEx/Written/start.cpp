#include <iostream>
#include "../Written/file2.h"
#include "handrail.h"

void fct1() {
    HTMLElement* p1 = new HTMLParagraph{ "Examination" };
    assert(p1->getHTMLString() == "<p>Examination</p>");
    HTMLElement* p2 = nullptr;
    HTMLElement* i1 = new HTMLImage{ "a.jpg" };
    HTMLElement* i2 = new HTMLImage{ "b.jpg" };
    assert(i2->getHTMLString() == "<img>b.jpg</img>");
    HTMLBuilder<HTMLElement*> html{};
    try {
        html += p2;
        assert(false);
    } catch (runtime_error& e) {
        assert(strcmp(e.what(), "Cannot add a null element!") == 0); }

    ((html += p1) += i1) += i2;
    cout << html; // prints: <html><body><p>Examination</p><img>a.jpg</img><img>b.jpg</img></html></body>
    delete p1; delete p2;
    delete i1; delete i2;
}

void handrail(){
    ///a simple wood stair, with 20 steps
    WoodStair* ws = new WoodStair{20};
    std::cout << ws->getDescription() << " " <<  ws->getPrice()<<"\n";
    delete ws;

    ///a metal stair, with 10 steps, with 5 linear meters of metal handrail
    MetalStair *stair1 = new MetalStair{10};
    MetalHandrail *handrail1 = new MetalHandrail{};
    StairWithHandrail *swh = new StairWithHandrail{stair1, handrail1, 5};
    std:cout << swh->getDescription() << " " << swh->Price()<<"\n";

    delete stair1;
    delete handrail1;
    delete swh;

    ///a wood stair with 10 steps,
    /// with 5 linear meters of wood handrail,
    /// with 10 vertical elements

    WoodStair *stair2 = new WoodStair{10};
    WoodHandrail *handrail2 = new WoodHandrail{};
    HandrailWithVerticalElements *handrailWithEl = new HandrailWithVerticalElements{handrail2, 10};
    StairWithHandrail *finalStair = new StairWithHandrail{stair2, handrailWithEl, 5};
    std::cout << finalStair->getDescription() << " " << finalStair->Price();

    delete stair2;
    delete handrail2;
    delete handrailWithEl;
    delete finalStair;
}
//
//int main(){
//    fct1();
//    handrail();
//    return 0;
//}