
#ifndef NODEMANAGER_H
#define NODEMANAGER_H

#include "includes.h"

namespace uitest
{
	namespace nodes
	{
		class Node;
		typedef std::vector<Node*> NodeList;
	}

	class NodeManager
	{
	public:
		NodeManager();
		~NodeManager();
		void addNode(nodes::Node* node);
		void removeNode(nodes::Node* node);

		void stop();
		void update() const;
	private:
		nodes::NodeList nodeList;
		bool running;
	};
}

#endif