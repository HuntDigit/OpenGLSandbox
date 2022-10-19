#pragma once
#include<vector>

class UINavigationController;

class ViewController
{

public:
	const char* title;
	UINavigationController* navigationController;
public:
	ViewController();
	virtual ~ViewController();

public:
	virtual void UpdateUI();
};

class UINavigationController : public ViewController
{
private:
	ViewController *rootController;
public:
	UINavigationController();
	UINavigationController(ViewController rootController);
	virtual ~UINavigationController() = default;

	virtual void pushViewController(ViewController viewController);
	virtual void popViewController();

public:
	std::vector<ViewController> viewControllers;

};



class FirstController : public ViewController
{
public:

public:
	FirstController();
	virtual ~FirstController() = default;

public:
	void UpdateUI() override;
};

class SecondController : public ViewController
{
public:

public:
	SecondController();
	virtual ~SecondController() = default;

public:
	void UpdateUI() override;
};