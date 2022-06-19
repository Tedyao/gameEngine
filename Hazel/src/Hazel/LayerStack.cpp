#include "hzpch.h"
#include "LayerStack.h"

namespace Hazel {
	LayerStack::LayerStack()
	{
		m_Layers = std::vector<Layer*>();
		m_LayerInsertIndex = 0;
	}

	LayerStack::~LayerStack() {
		for (Layer* layer : m_Layers) {
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;
	}

	void LayerStack::PushOverlay(Layer* layer)
	{
		m_Layers.emplace_back(layer);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto iter = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);
		if (iter != m_Layers.begin() + m_LayerInsertIndex) {
			m_Layers.erase(iter);
			m_LayerInsertIndex--;
		}
	}

	void LayerStack::PopOverlay(Layer* layer)
	{
		auto iter = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), layer);
		if (iter != m_Layers.end()) {
			m_Layers.erase(iter);
		}
	}

}

