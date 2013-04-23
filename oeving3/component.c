#include "component.h"

#include <stdlib.h>

// Creates a new component
component *component_create(component_function add, component_function tick, component_function remove) {
    // Allocate memory
    component *c = malloc(sizeof(component));
    
    // Set functions
    c->add_function = add;
    c->tick_function = tick;
    c->remove_function = remove;
    
    return c;
}

// Frees the memory used by a component
void component_dispose(component *c) {
    return; //TODO: Implement
}

// Adds a component to a gameobject
int component_add(gameobject *object, component *c, void *param) {
    // Expand arrays if needed
    if (object->components_size == object->components_capacity) {
        object->components_capacity *= 2;
        object->components = realloc(object->components, sizeof(component_function) * object->components_capacity);
        object->components_data = realloc(object->components_data, sizeof(void*) * object->components_capacity);
    }
    
    // Get nr (and increase index)
    int nr = object->components_size++;
    
    // Insert component
    object->components[nr] = c;
    
    // Call the component's add function
    c->add_function(nr, object, param);
    
    // Return nr
    return nr;
}

// Finds the component number of component in gameobject
// Return -1 if the component was not found
int component_find(gameobject *object, component *c) {
    return 0; //TODO: Implement
}

// Removes a component from a gameobject
int component_remove(gameobject *object, component *c, void *param) {
    return 0; //TODO: Implement
}

// Creates a new gameobject
gameobject* gameobject_create() {
    // Allocate struct
    gameobject *object = malloc(sizeof(gameobject));
    
    // Set initial capacity
    object->components_size = 0;
    object->components_capacity = 4; // TODO: Remove magic number?
    
    // Allocate arrays
    object->components = malloc(sizeof(component_function) * object->components_capacity);
    object->components_data = malloc(sizeof(void*) * object->components_capacity);
    
    return object;
}

// Frees the memory used by a gameobject
void gameobject_dispose(gameobject *object) {
    return; // TODO: Actually free some stuff
}