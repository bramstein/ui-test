
#ifndef NODE_H
#define NODE_H

namespace uitest
{
	class NodeManager;

	namespace nodes
	{
		class Node
		{
		public:
			/**
			* Called when the node is stopped.
			*/
			virtual void stop()	= 0;

			/**
			* Called when the node is added to the Manager.
			*/
			virtual void start() = 0;

			virtual void update() = 0;

			virtual void render() = 0;

			void setManager(NodeManager *m)
			{
				//assert(m);
				manager = m;
			}

			NodeManager * getManager() const
			{
				return manager;
			}
		private:
			NodeManager *manager;
		};
	}
}

#endif