/* Copyright (C) 2009 Wildfire Games.
 * This file is part of 0 A.D.
 *
 * 0 A.D. is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * 0 A.D. is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 0 A.D.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * ModelVertexRenderer that transforms models on the CPU but performs
 * lighting in a vertex shader.
 */

#ifndef INCLUDED_HWLIGHTINGMODELRENDERER
#define INCLUDED_HWLIGHTINGMODELRENDERER

#include "renderer/ModelVertexRenderer.h"

struct HWLightingModelRendererInternals;

/**
 * Class HWLightingModelRenderer: Render animated models using vertex
 * shaders for lighting.
 *
 * @note You should verify hardware capabilities using IsAvailable
 * before creating this model renderer.
 */
class HWLightingModelRenderer : public ModelVertexRenderer
{
public:
	/**
	 * HWLightingModelRenderer: Constructor.
	 *
	 * @param colorIsDiffuseOnly if true, the primary color sent to the fragment stage
	 * contains only the diffuse term, and not the ambient
	 */
	HWLightingModelRenderer(bool colorIsDiffuseOnly);
	~HWLightingModelRenderer();

	// Implementations
	void* CreateModelData(CModel* model);
	void UpdateModelData(CModel* model, void* data, int updateflags);
	void DestroyModelData(CModel* model, void* data);

	void BeginPass(int streamflags, const CMatrix3D* texturematrix);
	void EndPass(int streamflags);
	void PrepareModelDef(int streamflags, const CModelDefPtr& def);
	void RenderModel(int streamflags, CModel* model, void* data);

	/**
	 * IsAvailable: Determines whether this model renderer can be used
	 * given the OpenGL implementation specific limits.
	 *
	 * @note Do not attempt to construct a HWLightingModelRenderer object
	 * when IsAvailable returns false.
	 *
	 * @return true if the OpenGL implementation can support this
	 * model renderer.
	 */
	static bool IsAvailable();

protected:
	HWLightingModelRendererInternals* m;
};

/**
 * Render animated models using a ShaderRenderModifier.
 * This just passes through the vertex data directly; the modifier is responsible
 * for setting any shader uniforms etc.
 */
class ShaderModelRenderer : public HWLightingModelRenderer
{
public:
	ShaderModelRenderer();

	void BeginPass(int streamflags, const CMatrix3D* texturematrix);
	void EndPass(int streamflags);
	void RenderModel(int streamflags, CModel* model, void* data);
};


#endif // INCLUDED_HWLIGHTINGMODELRENDERER
