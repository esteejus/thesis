#!/usr/bin/env python
# coding: utf-8

# In[7]:


import plotly.graph_objects as go
from plotly.subplots import make_subplots
import pandas as pd
import numpy as np
from plotly.offline import iplot, init_notebook_mode
import matplotlib.pyplot as plt


# In[8]:


#codes with all L values
sn132_theory = pd.read_csv('Pion_Multiplicity_Theory - 132.csv', sep=',')
sn108_theory = pd.read_csv('Pion_Multiplicity_Theory - 108.csv', sep=',')
sn124_theory = pd.read_csv('Pion_Multiplicity_Theory - 124.csv', sep=',')

#codes with only min max L values
#sn132_theory = pd.read_csv('Pion_Multiplicity_Theory - Copy of 132.csv', sep=',')
#sn108_theory = pd.read_csv('Pion_Multiplicity_Theory - Copy of 108.csv', sep=',')
#sn124_theory = pd.read_csv('Pion_Multiplicity_Theory - Copy of 124.csv', sep=',')

sn132_theory['ratio'] = sn132_theory['pim']/sn132_theory['pip']
sn124_theory['ratio'] = sn124_theory['pim']/sn124_theory['pip']
sn108_theory['ratio'] = sn108_theory['pim']/sn108_theory['pip']


# In[9]:



sn132_theory_min = sn132_theory.reset_index()
sn132_theory_min = sn132_theory_min.loc[sn132_theory.groupby('name')['L'].idxmin()]

sn132_theory_max = sn132_theory.reset_index()
sn132_theory_max = sn132_theory_max.loc[sn132_theory.groupby('name')['L'].idxmax()]


sn124_theory_min = sn124_theory.reset_index()
sn124_theory_min = sn124_theory_min.loc[sn124_theory.groupby('name')['L'].idxmin()]

sn124_theory_max = sn124_theory.reset_index()
sn124_theory_max = sn124_theory_max.loc[sn124_theory.groupby('name')['L'].idxmax()]

sn108_theory_min = sn108_theory.reset_index()
sn108_theory_min = sn108_theory_min.loc[sn108_theory.groupby('name')['L'].idxmin()]

sn108_theory_max = sn108_theory.reset_index()
sn108_theory_max = sn108_theory_max.loc[sn108_theory.groupby('name')['L'].idxmax()]


# In[ ]:





# In[10]:


#fig = go.Figure()
fig = make_subplots(rows=3, cols=3,
                    shared_yaxes=True, vertical_spacing = 0.04, horizontal_spacing = 0.04)

#plot the soft pi-
fig.add_trace(go.Scatter(
        y = sn132_theory_min.name,
        x = sn132_theory_min.pim,
        name = 'Soft',
        marker=dict(
        color='rgba(156, 165, 196, 0.95)',
        line_color='rgba(156, 165, 196, 1.0)',
        )),row = 1, col = 1
)

fig.add_trace(go.Scatter(
        y = sn124_theory_min.name,
        x = sn124_theory_min.pim,
        name = 'Soft',
        showlegend=False,
        marker=dict(
        color='rgba(156, 165, 196, 0.95)',
        line_color='rgba(156, 165, 196, 1.0)',
        )), row = 1, col = 2
)

fig.add_trace(go.Scatter(
        y = sn108_theory_min.name,
        x = sn108_theory_min.pim,
        name = 'Soft',
        showlegend=False,
        marker=dict(
        color='rgba(156, 165, 196, 0.95)',
        line_color='rgba(156, 165, 196, 1.0)',
        )), row = 1, col = 3
)

#plot the stiff pi-
fig.add_trace(go.Scatter(
        y = sn132_theory_min.name,
        x = sn132_theory_min.pim,
        name = 'Stiff',
        marker=dict(
        color='rgba(156, 165, 196, 0.95)',
        line_color='rgba(156, 165, 196, 1.0)',
        )),row = 1, col = 1
)

fig.add_trace(go.Scatter(
        y = sn124_theory_min.name,
        x = sn124_theory_min.pim,
        name = 'Stiff',
        showlegend=False,
        marker=dict(
        color='rgba(156, 165, 196, 0.95)',
        line_color='rgba(156, 165, 196, 1.0)',
        )), row = 1, col = 2
)

fig.add_trace(go.Scatter(
        y = sn108_theory_min.name,
        x = sn108_theory_min.pim,
        name = 'Stiff',
        showlegend=False,
        marker=dict(
        color='rgba(156, 165, 196, 0.95)',
        line_color='rgba(156, 165, 196, 1.0)',
        )), row = 1, col = 3
)


#plot the stiff pi+
fig.add_trace(go.Scatter(
        y = sn132_theory_max.name,
        x = sn132_theory_max.pim,
        name = 'Stiff',
        showlegend=False,
        marker=dict(
        color='rgba(204, 204, 204, 0.95)',
        line_color='rgba(217, 217, 217, 1.0)'
        )),row = 1, col = 1
)

fig.add_trace(go.Scatter(
        y = sn124_theory_max.name,
        x = sn124_theory_max.pim,
        showlegend=False,
        name = 'Stiff',
        marker=dict(
        color='rgba(204, 204, 204, 0.95)',
        line_color='rgba(217, 217, 217, 1.0)'
        )), row = 1, col = 2
)

fig.add_trace(go.Scatter(
        y = sn108_theory_max.name,
        x = sn108_theory_max.pim,
        legendgroup = 'group1',
        showlegend=False,
        name = 'Stiff',
        marker=dict(
        color='rgba(204, 204, 204, 0.95)',
        line_color='rgba(217, 217, 217, 1.0)'
        )), row = 1, col = 3
)


#plot the soft pi+
fig.add_trace(go.Scatter(
        y = sn132_theory_min.name,
        x = sn132_theory_min.pip,
        name = 'Soft',
        showlegend=False,
        marker=dict(
        color='rgba(156, 165, 196, 0.95)',
        line_color='rgba(156, 165, 196, 1.0)',
        )),row = 2, col = 1
)

fig.add_trace(go.Scatter(
        y = sn124_theory_min.name,
        x = sn124_theory_min.pip,
        name = 'Soft',
        showlegend=False,
        marker=dict(
        color='rgba(156, 165, 196, 0.95)',
        line_color='rgba(156, 165, 196, 1.0)',
        )), row = 2, col = 2
)

fig.add_trace(go.Scatter(
        y = sn108_theory_min.name,
        x = sn108_theory_min.pip,
        name = 'Soft',
        showlegend=False,
        marker=dict(
        color='rgba(156, 165, 196, 0.95)',
        line_color='rgba(156, 165, 196, 1.0)',
        )), row = 2, col = 3
)


#plot the stiff pi+
fig.add_trace(go.Scatter(
        y = sn132_theory_max.name,
        x = sn132_theory_max.pip,
        name = 'Stiff',
        showlegend=False,
        marker=dict(
        color='rgba(204, 204, 204, 0.95)',
        line_color='rgba(217, 217, 217, 1.0)'
        )),row = 2, col = 1
)

fig.add_trace(go.Scatter(
        y = sn124_theory_max.name,
        x = sn124_theory_max.pip,
        showlegend=False,
        name = 'Stiff',
        marker=dict(
        color='rgba(204, 204, 204, 0.95)',
        line_color='rgba(217, 217, 217, 1.0)'
        )), row = 2, col = 2
)

fig.add_trace(go.Scatter(
        y = sn108_theory_max.name,
        x = sn108_theory_max.pip,
        legendgroup = 'group1',
        showlegend=False,
        name = 'Stiff',
        marker=dict(
        color='rgba(204, 204, 204, 0.95)',
        line_color='rgba(217, 217, 217, 1.0)'
        )), row = 2, col = 3
)


#plot the soft pi-/pi+
fig.add_trace(go.Scatter(
        y = sn132_theory_min.name,
        x = sn132_theory_min.ratio,
        name = 'Soft',
        showlegend=False,
        marker=dict(
        color='rgba(156, 165, 196, 0.95)',
        line_color='rgba(156, 165, 196, 1.0)',
        )),row = 3, col = 1
)

fig.add_trace(go.Scatter(
        y = sn124_theory_min.name,
        x = sn124_theory_min.ratio,
        name = 'Soft',
        showlegend=False,
        marker=dict(
        color='rgba(156, 165, 196, 0.95)',
        line_color='rgba(156, 165, 196, 1.0)',
        )), row = 3, col = 2
)

fig.add_trace(go.Scatter(
        y = sn108_theory_min.name,
        x = sn108_theory_min.ratio,
        name = 'Soft',
        showlegend=False,
        marker=dict(
        color='rgba(156, 165, 196, 0.95)',
        line_color='rgba(156, 165, 196, 1.0)',
        )), row = 3, col = 3
)


#plot the stiff pi-/pi+
fig.add_trace(go.Scatter(
        y = sn132_theory_max.name,
        x = sn132_theory_max.ratio,
        name = 'Stiff',
        showlegend=False,
        marker=dict(
        color='rgba(204, 204, 204, 0.95)',
        line_color='rgba(217, 217, 217, 1.0)'
        )),row = 3, col = 1
)

fig.add_trace(go.Scatter(
        y = sn124_theory_max.name,
        x = sn124_theory_max.ratio,
        showlegend=False,
        name = 'Stiff',
        marker=dict(
        color='rgba(204, 204, 204, 0.95)',
        line_color='rgba(217, 217, 217, 1.0)'
        )), row = 3, col = 2
)

fig.add_trace(go.Scatter(
        y = sn108_theory_max.name,
        x = sn108_theory_max.ratio,
        showlegend=False,
        name = 'Stiff',
        marker=dict(
        color='rgba(204, 204, 204, 0.95)',
        line_color='rgba(217, 217, 217, 1.0)'
        )), row = 3, col = 3
)


# In[ ]:





# In[11]:




# Add mean line for data measurment

pim_132 = .717
pip_132 = .148
ratio_132 = pim_132/pip_132

pim_124 = .522
pip_124 = .17
ratio_124 = pim_124/pip_124

pim_108 = .399
pip_108 = .2
ratio_108 = pim_108/pip_108

#error bars
pim_err_132 = .0242
pip_err_132 = .00553
ratio_err_132 = .12

pim_err_124 = .0303
pip_err_124 = .0128
ratio_err_124 = .24

pim_err_108 = .0142
pip_err_108 = .0086
ratio_err_108 = .0495

y0 = -1
y1 = 6.5


#rectangle represents error bar
fig.add_shape(type="rect", fillcolor='blue', opacity=.3, xref="x1", yref="y1",
            x0=pim_132-pim_err_132, y0=y0, x1=pim_132+pim_err_132, y1=y1)

fig.add_shape(type="rect", fillcolor='blue', opacity=.3, xref="x2", yref='y2',
             x0=pim_124-pim_err_124, y0=y0, x1=pim_124+pim_err_124, y1=y1)

fig.add_shape(type="rect", fillcolor='blue', opacity=.3, xref="x3", yref="y3",
             x0=pim_108-pim_err_108, y0=y0, x1=pim_108+pim_err_108, y1=y1)
        
fig.add_shape(type="rect", fillcolor='blue', opacity=.3, xref="x4", yref="y4",
            x0=pip_132-pip_err_132, y0=y0, x1=pip_132+pip_err_132, y1=y1)

fig.add_shape(type="rect", fillcolor='blue', opacity=.3, xref="x5", yref='y5',
             x0=pip_124-pip_err_124, y0=y0, x1=pip_124+pip_err_124, y1=y1)

fig.add_shape(type="rect", fillcolor='blue', opacity=.3, xref="x6", yref="y6",
             x0=pip_108-pip_err_108, y0=y0, x1=pip_108+pip_err_108, y1=y1)

fig.add_shape(type="rect", fillcolor='blue', opacity=.3, xref="x7", yref="y7",
            x0=ratio_132-ratio_err_132, y0=y0, x1=ratio_132+ratio_err_132, y1=y1)

fig.add_shape(type="rect", fillcolor='blue', opacity=.3, xref="x8", yref='y8',
             x0=ratio_124-ratio_err_124, y0=y0, x1=ratio_124+ratio_err_124, y1=y1)

fig.add_shape(type="rect", fillcolor='blue', opacity=.3, xref="x9", yref="y9",
             x0=ratio_108-ratio_err_108, y0=y0, x1=ratio_108+ratio_err_108, y1=y1)

        
        #lines represent mean value of measurment
fig.add_shape(type="line", xref="x1", yref="y1",
            x0=pim_132, y0=y0, x1=pim_132, y1=y1, line_width=3)

fig.add_shape(type="line", xref="x2", yref='y2',
             x0=pim_124, y0=y0, x1=pim_124, y1=y1, line_width=3)

fig.add_shape(type="line", xref="x3", yref="y3",
             x0=pim_108, y0=y0, x1=pim_108, y1=y1, line_width=3)

fig.add_shape(type="line", xref="x4", yref="y4",
            x0=pip_132, y0=y0, x1=pip_132, y1=y1, line_width=3)
    
fig.add_shape(type="line", xref="x5", yref='y5',
             x0=pip_124, y0=y0, x1=pip_124, y1=y1, line_width=3)

fig.add_shape(type="line", xref="x6", yref="y6",
             x0=pip_108, y0=y0, x1=pip_108, y1=y1, line_width=3)
        
fig.add_shape(type="line", xref="x7", yref="y7",
            x0=ratio_132, y0=y0, x1=ratio_132, y1=y1, line_width=3)

fig.add_shape(type="line", xref="x8", yref='y8',
             x0=ratio_124, y0=y0, x1=ratio_124, y1=y1, line_width=3)

fig.add_shape(type="line", xref="x9", yref="y9",
             x0=ratio_108, y0=y0, x1=ratio_108, y1=y1, line_width=3)


# In[12]:


fig.update_xaxes(range=[.2,1], dtick = .2, row = 1, col = 1,  linecolor='rgb(102, 102, 102)',
        tickfont_color='rgb(102, 102, 102)',
        showticklabels=True,
        ticks='outside',
        tickcolor='rgb(102, 102, 102)')
fig.update_xaxes(range=[.2,.8], dtick = .2, row = 1, col = 2,  linecolor='rgb(102, 102, 102)',
        tickfont_color='rgb(102, 102, 102)',
        showticklabels=True,
        ticks='outside',
        tickcolor='rgb(102, 102, 102)')

fig.update_xaxes(range=[.1,.55], dtick = .2, row = 1, col = 3,  linecolor='rgb(102, 102, 102)',
        tickfont_color='rgb(102, 102, 102)',
        showticklabels=True,
        ticks='outside',
        tickcolor='rgb(102, 102, 102)',
        )

fig.update_xaxes(range=[.05,.25], dtick = .1, row = 2, col = 1,  linecolor='rgb(102, 102, 102)',
        tickfont_color='rgb(102, 102, 102)',
        showticklabels=True,
        ticks='outside',
        tickcolor='rgb(102, 102, 102)')
fig.update_xaxes(range=[.05,.3], dtick = .1, row = 2, col = 2,  linecolor='rgb(102, 102, 102)',
        tickfont_color='rgb(102, 102, 102)',
        showticklabels=True,
        ticks='outside',
        tickcolor='rgb(102, 102, 102)')

fig.update_xaxes(range=[.05,.3], dtick = .1, row = 2, col = 3,  linecolor='rgb(102, 102, 102)',
        tickfont_color='rgb(102, 102, 102)',
        showticklabels=True,
        ticks='outside',
        tickcolor='rgb(102, 102, 102)',
        )



fig.update_xaxes(range=[2.,6.5], dtick = 1, row = 3, col = 1,  linecolor='rgb(102, 102, 102)',
        title_text= "132Sn + 124Sn",
        tickfont_color='rgb(102, 102, 102)',
        showticklabels=True,
        ticks='outside',
        tickcolor='rgb(102, 102, 102)')
fig.update_xaxes(range=[1.5,4.5], dtick = 1, row = 3, col = 2,  linecolor='rgb(102, 102, 102)',
        title_text="124Sn + 112Sn",
        tickfont_color='rgb(102, 102, 102)',
        showticklabels=True,
        ticks='outside',
        tickcolor='rgb(102, 102, 102)')

fig.update_xaxes(range=[.5,3.5], dtick = 1, row = 3, col = 3,  linecolor='rgb(102, 102, 102)',
        title_text="108Sn + 112Sn",
        tickfont_color='rgb(102, 102, 102)',
        showticklabels=True,
        ticks='outside',
        tickcolor='rgb(102, 102, 102)',
        )


fig.update_yaxes(row = 1, col = 1, 
        title_text= "r'$\pi^{-}$",
        titlefont=dict(
           # family='Courier New, monospace',
            size=100,
          #  color='#7f7f7f'
        )
                )

fig.update_yaxes( row = 2, col = 1, 
        title_text="r'$\pi^{+}$",
   
                )

fig.update_yaxes(row = 3, col = 1,  
        title_text="r'$\pi^{-}/\pi^{+}$",
     
        )


fig.update_traces(mode='markers', marker=dict(line_width=1, symbol='circle', size=16))



#fig.update_xaxes(range=[.05,.25], dtick = .1, row = 1, col = 2)

fig.update_layout(
    title="",
    margin=dict(l=50, r=80, b=50, t=80),
    font=dict(
       # family="Courier New, monospace",
        size=20,
    #    color="#7f7f7f"
    ),
    legend=dict(
        font_size=20,
        yanchor='middle',
        xanchor='right',
    ),
    width=1000,
    height=800,
    paper_bgcolor='white',
    plot_bgcolor='white',
    hovermode='closest',
)

fig.write_image("pionpaper.pdf")

fig.show()


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




