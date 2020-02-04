/*
 * State.h
 *
 *  Created on: 25-Sep-2019
 *      Author: pluto
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Exceptions.h"

class Scene {
  private:
	bool pauseable;
	bool isPaused;
	bool willChangeScene = false;

  protected:
	Scene* newScene;
	virtual void setNewScene(Scene* newScene);

  public:
	Scene(bool pauseable);
	virtual ~Scene();
	bool getIsPaused() const;
	virtual void pause();	//Do not forget to set isPaused to true
	bool isPauseable() const;

	virtual void update(const float delta) = 0;
	virtual void draw(sf::RenderWindow & window) const = 0;
	virtual bool getWillChangeScene() const;
	virtual Scene* getNewScene() const;

	virtual void actionOnMouseClick(sf::Mouse::Button, const sf::RenderWindow* window, const float delta) = 0;
	virtual void actionOnMouseMove(const sf::RenderWindow* window, const float delta) = 0;
	virtual void actionOnKeyPress(sf::Keyboard::Key, const float delta) = 0;
	virtual void actionOnKeyRelase(sf::Keyboard::Key, const float delta) = 0;
};

#endif /* SCENE_H_ */
