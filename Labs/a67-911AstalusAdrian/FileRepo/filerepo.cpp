#include "filerepo.h"
#include "../Exceptions/exception.h"

FileRepository::FileRepository(const std::string& filename) {
    this->file_name = filename;
}

FileRepository::~FileRepository() {

}

void FileRepository::addDog(const Dog &dog) {
    std::vector<Dog> dogs = read();
    if(getIndex(dog) >= 0)
        throw RepositoryException("This dog is already in the shelter!\n");
    dogs.push_back(dog);
    write(dogs);
}

void FileRepository::removeDog(const Dog &dog) {
    std::vector<Dog> dogs = read();
    int index = getIndex(dog);
    if(index < 0)
        throw RepositoryException("This dog is not in the shelter!\n");
    dogs.erase(dogs.begin() + index);
    write(dogs);
}

void FileRepository::updateDog(const Dog &dog, const Dog &new_dog) {
    std::vector<Dog> dogs = read();
    int index = getIndex(dog);
    if(index < 0)
        throw RepositoryException("This dog is not in the shelter!\n");
    dogs[index] = new_dog;
    write(dogs);
}

Dog FileRepository::getDog(int index) {
    if (index < 0 || index >= nrDogs())
        throw RepositoryException("This is not a valid index!\n");
    std::vector<Dog> dogs = read();
    return dogs[index];
}

int FileRepository::nrDogs() {
    std::vector<Dog> dogs = read();
    return (int)dogs.size();
}

int FileRepository::getIndex(const Dog &dog) {
    std::vector<Dog> dogs = read();
    int i = 0;
    for (const auto& each_dog : dogs){
        if (each_dog == dog)
            return i;
        i++;
    }
    return -1;
}

vector<Dog> FileRepository::getRepo() {
    std::vector<Dog> dogs_repo;
    std::vector<Dog> all_dogs = read();
    dogs_repo.reserve(nrDogs());
    for (const auto& dog : all_dogs)
        dogs_repo.push_back(dog);
    return dogs_repo;
}

std::vector<Dog> FileRepository::read() {
    std::ifstream in(this->file_name);
    Dog current_dog;
    std::vector<Dog> all_dogs;
    while(in >> current_dog)
        all_dogs.push_back(current_dog);
    return all_dogs;
}

void FileRepository::write(std::vector<Dog> dogs) {
    std::ofstream out(this->file_name);
    for (const auto& dog: dogs)
        out << dog << "\n";
}
