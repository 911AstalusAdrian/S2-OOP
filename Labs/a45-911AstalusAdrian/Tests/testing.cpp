#include <dog.h>
#include <../DynamicArray/dynamic_array.h>
#include <../Repository/reopsitory.h>
#include <../Service/service.h>
#include <../userService/userservice.h>
#include <../Validation/validators.h>
#include "testing.h"
#include <assert.h>

void test_entity(){
    Dog dog = Dog("Husky", "Luna", 5, "picture_link");
    assert(dog.getBreed() == "Husky");
    assert(dog.getName() == "Luna");
    assert(dog.getAge() == 5);
    assert(dog.getPhoto() == "picture_link");
    Dog copy_dog = dog;
    assert(copy_dog.getBreed() == "Husky");
    assert(copy_dog.getName() == "Luna");
    assert(copy_dog.getAge() == 5);
    assert(copy_dog.getPhoto() == "picture_link");
    copy_dog.setBreed("German Shepherd");
    copy_dog.setName("Max");
    copy_dog.setAge(7);
    copy_dog.setPhoto("new_picture_link");
    assert(copy_dog.getBreed() == "German Shepherd");
    assert(copy_dog.getName() == "Max");
    assert(copy_dog.getAge() == 7);
    assert(copy_dog.getPhoto() == "new_picture_link");
    assert(copy_dog.toString() == "Max - German Shepherd, 7 year(s) old, and here's a pic: new_picture_link");
}

void test_da(){
    Dog dog_1 = Dog("Husky", "Luna", 5, "picture_link");
    Dog dog_2 = Dog("German Shepherd", "Max", 7, "pic_link2");
    Dog dog_3 = Dog("Bulldog", "Lucas", 4, "pic_link3");
    DynamicArray<Dog> da = DynamicArray<Dog>(2);
    assert(da.arrayLength() == 0);
    assert(da.arrayCapacity() == 2);
    da.add(dog_1);
    assert(da.arrayLength() == 1);
    da.add(dog_2);
    assert(da.arrayLength() == 2);
    da.add(dog_3);
    assert(da.arrayCapacity() == 4);
    assert(da.arrayLength() == 3);
    assert(da.findElem(dog_1) == 0);
    da.remove(dog_1);
    assert(da.findElem(dog_1) == -1);
    Dog another_dog = da.getElem(0);
    da.update(dog_2, dog_1);
    DynamicArray<Dog> new_da = da;
    assert(new_da.arrayLength() == 2);
    assert(new_da.arrayCapacity() == 4);
}

void test_repo(){
    Dog dog_1 = Dog("Husky", "Luna", 5, "picture_link");
    Dog dog_2 = Dog("German Shepherd", "Max", 7, "pic_link2");
    Dog dog_3 = Dog("Bulldog", "Lucas", 4, "pic_link3");
    DynamicArray<Dog> da = DynamicArray<Dog>(2);
    Repository repo = Repository(&da);
    repo.addDog(dog_2);
    assert(repo.addDog(dog_1) == 1);
    assert(repo.addDog(dog_1) == -1);
    assert(repo.removeDog(dog_1) == 1);
    assert(repo.removeDog(dog_1) == -1);
    assert(repo.updateDog(dog_2, dog_3) == 1);
    assert(repo.updateDog(dog_1, dog_2) == -1);
    DynamicArray<Dog>* new_da = repo.getArray();
    Dog another_dog = repo.getDog(0);
    assert(another_dog == dog_3);
    assert(repo.findDog(dog_3) == 1);
    assert(repo.findDog(dog_1) == -1);
    assert(repo.nrDogs() == 1);
}

void test_service(){
    Dog dog_1 = Dog("Husky", "Luna", 5, "picture_link");
    Dog dog_2 = Dog("German Shepherd", "Max", 7, "pic_link2");
    Dog dog_3 = Dog("Bulldog", "Lucas", 4, "pic_link3");
    DynamicArray<Dog> da = DynamicArray<Dog>(2);
    Repository repo = Repository(&da);
    Service service = Service(&repo);
    assert(service.addDogService("Husky", "Luna", 5, "pic_link1") == 1);
    assert(service.addDogService("German Shepherd", "Max", 7, "pic_link2") == 1);
    assert(service.addDogService("Bulldog", "Lucas", 4, "pic_link3") == 1);
    assert(service.addDogService("Husky", "Luna", 5, "pic_link1") == -1);
    assert(service.addDogService("Husky", "Luna", -1, "link") == -1);
    assert(service.removeDogServiceByIndex(0) == 1);
    assert(service.removeDogServiceByIndex(10) == -1);
    assert(service.updateDogService(dog_2, dog_3) == 1);
    assert(service.updateDogService(dog_1, dog_2) == -1);
    assert(service.getNumberOfDogs() == 2);
    Dog dogdog = service.getDogByIndex(0);
    assert(dogdog.getBreed() == "Bulldog");
    DynamicArray<Dog>* new_da = service.getArray();
    assert(new_da->arrayLength() == 2);
}

void test_user_service(){
    Dog dog_1 = Dog("Husky", "Luna", 5, "picture_link");
    Dog dog_2 = Dog("German Shepherd", "Max", 7, "pic_link2");
    Dog dog_3 = Dog("Bulldog", "Lucas", 4, "pic_link3");
    Dog dog_4 = Dog("English Bulldog", "Terry", 6, "pic_link4");
    DynamicArray<Dog> da = DynamicArray<Dog>(2);
    Repository repo = Repository(&da);
    userService us = userService(&repo);
    repo.addDog(dog_1);
    repo.addDog(dog_2);
    repo.addDog(dog_4);
    repo.addDog(dog_3);
    DynamicArray<Dog> filtered = us.filterDogs("Bulldog", 8);
    assert(filtered.arrayLength() == 2);
    DynamicArray<Dog> adlist = us.seeAdoptionList();
    assert(adlist.arrayLength() == 0);
    assert(us.addToAdoption(dog_1) == 1);
    assert(us.addToAdoption(dog_1) == -1);
    DynamicArray<Dog> adlist2 = us.seeAdoptionList();
    assert(adlist2.arrayLength() == 1);
}

void test_validation(){
    Dog dog_1 = Dog("German Shepherd", "Max", 7, "pic_link2");
    assert(validate_breed("Husky") == 0);
    assert(validate_breed("") == 1);
    assert(validate_name("Luna") == 0);
    assert(validate_name("") == 1);
    assert(validate_age(2) == 0);
    assert(validate_age(-1) == 1);
    assert(validate_link("link") == 0);
    assert(validate_link("") == 1);
    Dog dog_2 = Dog("German Shepherd", "Max", 7, "pic_link2");
    assert(validate_entity(dog_2) == 0);
    dog_2.setName("");
    assert(validate_entity(dog_2) == 1);
    dog_2 = dog_1;
    dog_2.setPhoto("");
    assert(validate_entity(dog_2) == 1);
    dog_2 = dog_1;
    dog_2.setAge(0);
    assert(validate_entity(dog_2) == 1);
    dog_2 = dog_1;
    dog_2.setBreed("");
    assert(validate_entity(dog_2) == 1);


}

void test_all(){
    test_entity();
    test_da();
    test_repo();
    test_service();
    test_user_service();
    test_validation();
}