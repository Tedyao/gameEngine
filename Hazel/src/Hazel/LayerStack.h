#pragma once

#include "Core.h"
#include "Layer.h"
#include <vector>
#include <string>

namespace Hazel {
	class HAZEL_API LayerStack {
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* layer);

		inline std::vector<Layer*>::iterator begin() {
			return m_Layers.begin();
		}
		inline std::vector<Layer*>::iterator end() {
			return m_Layers.end();
		}

		inline std::string ToString() {
		
			std::stringstream ss;
			for (Layer* layer : m_Layers) {
				ss << "Layer: (" << layer->GetDebugName() << ") ";
			}
			return ss.str();
		}

	private:
		std::vector<Layer*> m_Layers;
		unsigned int m_LayerInsertIndex;
	};
}
