#include ".\NodeManager.h"
#include ".\Node.h"

namespace uitest
{
	NodeManager::NodeManager() : running(true)
	{
	}

	NodeManager::~NodeManager()
	{
		nodes::NodeList::iterator i;
		for(i = nodeList.begin(); i != nodeList.end(); ++i)
		{
			(*i)->stop();
			delete (*i);
		}
		nodeList.clear();
	}

	void NodeManager::addNode(nodes::Node* node)
	{
		node->setManager(this);
		node->start();
		nodeList.push_back(node);
	}

	void NodeManager::removeNode(nodes::Node* node)
	{
		node->setManager(0);
		node->stop();
		nodes::NodeList::iterator i(std::find(nodeList.begin(),nodeList.end(),node));

		if(i != nodeList.end())
		{
			delete (*i);
			nodeList.erase(i);
		}
	}

	void NodeManager::stop()
	{
		running = false;
	}

	void NodeManager::update() const
	{
		while(running && nodeList.size() > 0)
		{
			nodes::NodeList::const_iterator updateIter;
			for(updateIter = nodeList.begin(); updateIter != nodeList.end(); ++updateIter)
			{
				(*updateIter)->update();
			}

			nodes::NodeList::const_iterator renderIter;
			for(renderIter = nodeList.begin(); renderIter != nodeList.end(); ++renderIter)
			{
				(*renderIter)->render();
			}
		}
	}
}