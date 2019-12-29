/*
 * State.cpp
 *
 *  Created on: 25-Sep-2019
 *      Author: pluto
 */

#include "Scene.h"

Scene::Scene(bool pauseable) : pauseable(pauseable) {
	Scene::isPaused = false;
}

bool Scene::getIsPaused() const {
	return Scene::isPaused;
}

void Scene::setNewScene(Scene* newScene) {
	willChangeScene = true;
	Scene::newScene = newScene;
}

void Scene::pause() {
	if(Scene::pauseable)Scene::isPaused = true;
	else {
		std::cerr << "Invalid operation\n";
		throw EXCEPTION_INVALID_OPERATION;
	}
}

bool Scene::isPauseable() const {
	return Scene::pauseable;
}

Scene::~Scene() {
	delete newScene;
}


bool Scene::getWillChangeScene() const {
	return willChangeScene;
}

Scene* Scene::getNewScene() const {
	if(getWillChangeScene()) {
		return newScene;
	} else {
		std::cerr << "Invalid operation\n";
		throw EXCEPTION_INVALID_OPERATION;
	}
}
